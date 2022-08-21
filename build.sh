ROOT_DIR=/home/darko/Development/cpp-edu
COMPILE_CMD="make"

CONFIGURE=false
WIN_CONFIG=Release
TARGET=
EXE=
RUN=false

while getopts "t:cdr" option; do
    case $option in
        c)
            CONFIGURE=true
            ;;
        d)
            WIN_CONFIG=Debug
            ;;
        t)
            TARGET=$OPTARG
            EXE=./$TARGET
            ;;
        r) RUN=true
           ;;
    esac
done

validate_exit() {
    if [ $? != 0 ]; then
        exit 1
    fi
}

if [ "$OSTYPE" = "msys" ]; then
    WIN=true
    
    COMPILE_CMD="MSBuild.exe -target:Build /property:Configuration=${WIN_CONFIG}"
    ROOT_DIR=c:/Users/darko/Development/cpp-edu
fi

if [ $CONFIGURE = true ]; then
    echo "INFO: configure MSBuild"
    cd ${ROOT_DIR}/build
    cmake ..
    validate_exit

    if [ "$WIN" == true ]; then    
        echo "INFO: configure Ninja"    
        cd $ROOT_DIR/ninja/
        cmake -G"Ninja" ..
        mv compile_commands.json ..
        validate_exit
    fi
    
    exit 0
fi

if [ -z ${TARGET} ]; then
    exit 0
fi

if [ "$WIN" == true ]; then
    EXE=.\\${TARGET}.exe
    TARGET=${TARGET}.vcxproj
fi
   
cd $ROOT_DIR/build
echo "COMPILE_CMD: $COMPILE_CMD $TARGET"
$COMPILE_CMD $TARGET
validate_exit

if [ "$RUN" == true ]; then
    cd $ROOT_DIR/bin
    echo "EXE_CMD: ${EXE}"
    ${EXE}
fi
