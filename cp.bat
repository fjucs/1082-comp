@echo off
echo Compiling...

set WEEK=2
g++ -std=c++11 week%WEEK%/%1.cpp -o week%WEEK%/%1.exe
if %ERRORLEVEL% EQU 0 (
	echo END
	"week%WEEK%/%1.exe" < week%WEEK%/%1.in > week%WEEK%/%1.out
)