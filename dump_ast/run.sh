#!/bin/bash
clang++ -fplugin=./dump_ast.so test.cc -o test
