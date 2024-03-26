
dump_ast:
	clang++ -isystem /usr/lib/llvm-14/include \
		-fPIC \
		-std=gnu++20 \
		-shared \
		dump_ast.cc \
		-o dump_ast.so

clean:
	rm dump_ast.so test
