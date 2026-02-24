#!/bin/bash

mkdir -p bin
mkdir -p data

g++ main.cpp src/*.cpp -o bin/main.out -I./inc -I./externals -ltinyxml2

./bin/main.out