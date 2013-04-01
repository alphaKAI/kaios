cd sugarless12/
cp base64.h ../
gcc -c base64.c
ar rv -o base64.a base64.o
cp *.a ../
cd ../
gcc -c main.c
gcc -c my_lib.c
ar rv -o my_lib.a my_lib.o
gcc -c kernel.c 
gcc -o kaios main.o kernel.o *.a
