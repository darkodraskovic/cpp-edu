# C++ examples

The examples can be found in the *Source* directory. Examples prefixed with

- `bw` correspond to Bill Weinmann's [C++: Advanced Topics](https://www.lynda.com/C-tutorials/C-Advanced-Programming-Topics/782128-2.html) course,
- `kk` correspond to Jan Schaffranek's [C++ Komplettkurs: Praxisnahe und Moderne C++ Programmierung](https://www.udemy.com/course/der-komplettkurs-zur-modernen-c-programmierung/) course,
- `dd` are examples that I have created to test and understand C++ features refereed to by the aforementioned courses.

## Install

### CMake

Install [CMake](https://cmake.org/).

`mkdir` `build` directory. `cd` into `build` directory and run

```
cmake ..
make
./main
```

### clangd

Install [clangd](https://clangd.llvm.org/installation.html).

`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```
ln -s build/compile_commands.json .
```

## Run

```
make <target_name> && ./<target_name>
```

For <target_name> consult `CMakeLists.txt`. Target names correspond to examples directory names.
