
@SET CC=cl
@SET PART1=main
@SET PART2=kernel
@SET PART3=my_lib
@SET SRC=.c
@SET PROG=kaios
@SET LIBS=Advapi32.lib Kernel32.lib

@if "%2"=="" goto defo
@if "%2"=="main" goto main
@if "%2"=="kaernel" goto kernel
@if "%2"=="my_lib" goto my_lib
@if "%2"=="link" goto link

:defo
@rem make objs
%CC% /Fe%PROG% %PART1%%SRC% %PART2%%SRC% %PART3%%SRC% %LIBS%
@goto :EOF

:main
%CC% /c %PART1%%SRC%
@goto :EOF

:kernel
%CC% /c %PART2%%SRC%
@goto :EOF

:my_lib
%CC% /c %PART3%%SRC%
@goto :EOF

:link
%CC% /Fe%PROG% %PART1%%OBJ% %PART2%%OBJ% %PART3%%OBJ% %LIBS%
@goto :EOF
