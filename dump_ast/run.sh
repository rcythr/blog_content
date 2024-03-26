#!/bin/bash

set -e

make 

clang++ -fplugin=./dump_ast.so test.cc -o test
