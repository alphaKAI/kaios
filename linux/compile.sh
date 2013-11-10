cd src/obj
gcc -c ../main.c
gcc -c ../my_lib.c
gcc -c ../kernel.c
gcc -o ../../kaios main.o kernel.o my_lib.o
