
@SET CC=cl
@SET PART1=main
@SET PART2=kernel
@SET SRC=.c
@SET OBJ=.obj
@SET PROG=kaios
@SET LIBS=my_lib.lib Advapi32.lib Kernel32.lib

@if "%2"=="" goto defo
@if "%2"=="main" goto main
@if "%2"=="kaernel" goto kernel

@if "%2"=="kaernel" goto link

:defo
@rem make objs
%CC% /c %PART1%%SRC%
%CC% /c %PART2%%SRC%
%CC% /Fe%PROG% %PART1%%OBJ% %PART2%%OBJ% %LIBS%
@goto :EOF

:main
%CC% /c %PART1%%SRC%
@goto :EOF

:kernel
%CC% /c %PART2%%SRC%
@goto :EOF

:link
%CC% /Fe%PROG% %PART1%%OBJ% %PART2%%OBJ% %LIBS%
@goto :EOF
