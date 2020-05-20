@echo off
echo Compiling...
cls
set WEEK=11
g++ -std=c++11 -g week%WEEK%/%1.cpp -o week%WEEK%/%1.exe
if %ERRORLEVEL% EQU 0 (
	echo END
	powershell "Get-Content week%WEEK%/%1.in | week%WEEK%/%1.exe | tee week%WEEK%/%1.out"
)