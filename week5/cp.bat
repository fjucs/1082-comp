@echo off
cls
echo Compiling...
g++ -std=c++11 %1.cpp -o %1.exe
if %ERRORLEVEL% EQU 0 (
	echo RUN
	%1.exe < %1.in > %1.out
	echo END
)