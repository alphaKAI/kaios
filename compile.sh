gcc -c main.c
gcc -c my_lib.c
ar rv -o my_lib.a my_lib.o
gcc -c kernel.c 
gcc -o kaios main.o kernel.o my_lib.a
