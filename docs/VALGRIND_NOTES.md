# VALGRIND ANALYSIS NOTES

## COMMAND USED FOR ANALYSIS SESSION

- MAKE version
```sh
make valgrind
```

- BASH version (VERBOSE)
```sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  	--log-file=valgrind_report.txt \
    ./bin/tic-tac-toe
```

## FINAL OUTPUT

0 memory leaks detected, 2 tracked allocations correctly freed
