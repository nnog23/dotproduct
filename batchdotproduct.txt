nasm -f win64 dotproduct.asm
gcc -c caller.c -o caller.obj -m64
gcc caller.obj dotproduct.obj -o caller.exe -m64
caller.exe