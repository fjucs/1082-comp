#!/bin/bash

echo Gen $1 $2
cat template.cpp > "./week$1/$2.cpp"
touch "./week$1/$2.in" "./week$1/$2.out"