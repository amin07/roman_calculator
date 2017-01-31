all: ../bin/exe test_exe
../bin/exe: roman_ops.o lib_romanops.a
	gcc -o ../bin/driver_exe -I../include/ ../driver.c -L../lib -l_romanops

lib_romanops.a: roman_ops.o
	ar rcs ../lib/lib_romanops.a ../obj/roman_ops.o
	ranlib ../lib/lib_romanops.a
roman_ops.o:
	gcc -c ../src/roman_ops.c -I../include -o ../obj/roman_ops.o

test_exe:
	gcc roman_tests.c -o test_exe -I../include -L../lib -l_romanops `pkg-config --cflags --libs check`
clean:
	rm test_exe
	rm ../obj/* ../bin/* ../lib/*
.PHONY: all test_exe clean

