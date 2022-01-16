# C++ examples

The examples can be found in the *Source* directory. Examples prefixed with

- `bw` correspond to Bill Weinmann's [C++: Advanced Topics](https://www.lynda.com/C-tutorials/C-Advanced-Programming-Topics/782128-2.html) course,
- `kk` correspond to Jan Schaffranek's [C++ Komplettkurs: Praxisnahe und Moderne C++ Programmierung](https://www.udemy.com/course/der-komplettkurs-zur-modernen-c-programmierung/) course,
- `hc` correspond to Huw Collingbourne's [Advanced C Programming: Pointers](https://www.udemy.com/course/advanced-c-programming-pointers/) course
- `dd` are examples that I have created to test and understand various C/C++ features

## Linux build

Install [CMake](https://cmake.org/).

`mkdir` `build` directory. `cd` into `build` directory and run

```
cmake ..
make <target>
./<target>
```

For <target> consult `CMakeLists.txt`. Target names correspond to examples directory names.

## Windows build

### MSBuild.exe

Download and install [Build Tools for Visual Studio 2019](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019).

Download and install [CMake](https://cmake.org/).

`mkdir` `build` directory. `cd` into `build` directory and run

```
cmake ..
MSBuild.exe -target:"Build;Run" /property:Configuration=Release .\<target>.vcxproj
```
For <target> consult `CMakeLists.txt`. Target names correspond to examples directory names.

### MinGW

To configure and generate
```
cd build/ && cmake -G"Unix Makefiles" ..
```

To compile, link and run

```
cd build/ && make <target> && <target>.exe
```
## clangd

Install [clangd](https://clangd.llvm.org/installation.html).

`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```
ln -s build/compile_commands.json .
```
