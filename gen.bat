@echo off
set WEEK=10
echo Gen week%WEEK%/%1
type template.cpp > week%WEEK%/%1.cpp
echo.>week%WEEK%/%1.in
echo.>week%WEEK%/%1.out