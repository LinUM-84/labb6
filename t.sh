#/bin/sh
rm *.o
rm test
gcc -std=c99 -fno-builtin -c resistancecalc.c -o resistancecalc.o
gcc -std=c99 -fno-builtin -c test_rescalc.c -o test_rescalc.o
gcc -std=c99 -fno-builtin test_rescalc.o resistancecalc.o -lm -o test
./test

