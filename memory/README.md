# memory (for study purpose only)

## AddressSanitizer
build with `-fsanitize=address` flag.  
```shell script
./memory [option]
# run ./memory to see options
```

## valgrind
build without `-fsanitize=address` flag.  
```shell script
valgrind --tool=memcheck --leak-check=full ./memory -l
```
## gdb
build without `-fsanitize=address` flag.  
```shell script
gdb

file ./memory
set args -g
watch *((char *)&l_choices)
run
```