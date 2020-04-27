#!/bin/bash

echo Compiling...
g++ -std=c++17 "./week$1/$2.cpp" -o "./week$1/$2.exe"
if [[ $? -eq 0 ]]; then
    echo Running
    "./week$1/$2.exe" < "./week$1/$2.in" > "./week$1/$2.out"
    echo END
fi