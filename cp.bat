@echo off
echo Compiling...

set WEEK=10
g++ -std=c++11 -g week%WEEK%/%1.cpp -o week%WEEK%/%1.exe
if %ERRORLEVEL% EQU 0 (
	echo END
	"week%WEEK%/%1.exe" < week%WEEK%/%1.in > week%WEEK%/%1.out
)