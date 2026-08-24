# Tris (Tic Tac Toe) in C

![CI](https://github.com/MicheleBenedic/Tic-Tac-Toe/actions/workflows/ci.yml/badge.svg)

Tic-Tac-Toe project written in C, made with the **EDUBE C Essentials 1** concepts track 
(OpenEDG / Cisco Networking Academy): variables, operators, if statements, loops,
functions and arrays.

## Project's structure

```tree
tic-tac-toe/
├── LICENSE
├── Makefile
├── README.md
├── docker.sh
├── dockerfile
├── docs
│   └── VALGRIND_NOTES.md
├── gen_compdb.py
├── gitpush.sh
├── lib
│   └── unity
├── src
│   ├── game.c
│   ├── game.h
│   └── main.c
└── tests
    ├── test_game.c
    └── unity
        ├── unity.c
        ├── unity.h
        └── unity_internals.h
```

## Pre-requisites

- `clang` (tested with `clang-22`, standard C23)
- `make` (optional)
- `clang-format` / `clang-tidy` (optional)

## How to compile and execute

### With Makefile

```sh
make          # compiles (debug build, with AddressSanitizer/UBSan)
make run      # compiles and executes
make release  #  optimized build, without sanitizers
make clean    # removes generated files
```

### With VSCode

- `Alt+F1`: compiles and executes the current C file
- `Alt+F2`: activates the debugger (lldb) over the current file

### Manually

```sh
clang-22 -std=c23 -Wall -Wextra -Wpedantic -Wconversion -g src/main.c -o tic-tac-toe
./tic-tac-toe
```
or...

```sh
clang-22 -std=c23 -Wall -Wextra -Wpedantic -Wconversion -02 src/main.c -o tic-tac-toe
./tic-tac-toe
```

## Project's status

PROJECT COMPLETED

## License

Distrubuited under MIT license. Read [LICENSE](LICENSE).
