PROJ_DIR=c:/Users/darko/Development/cpp-edu

CONFIGURE=false
CONFIGURATION=Release
TARGET=
RUN=false

while getopts "t:cdr" option; do
    case $option in
        c)
            CONFIGURE=true
            ;;
        d)
            CONFIGURATION=Debug
            ;;
        t)
            TARGET=$OPTARG
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

if [ $CONFIGURE = true ]; then
    echo "INFO: configure MSBuild"
    cd ${PROJ_DIR}/build
    cmake ..
    validate_exit

    echo "INFO: configure Ninja"    
    cd $PROJ_DIR/ninja/
    cmake -G"Ninja" ..
    mv compile_commands.json ..
    validate_exit

    exit 0
fi

if [ -z ${TARGET} ]; then
    exit 0
fi
   
cd $PROJ_DIR/build
MSBuild.exe -target:"Build" /property:Configuration=${CONFIGURATION} .\\${TARGET}.vcxproj
validate_exit

if [ $RUN == true ]; then
    cd $PROJ_DIR/bin
    .\\${TARGET}.exe
fi
