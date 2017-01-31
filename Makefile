./bin/exe: roman_ops.o lib_romanops.a
	gcc -o ./bin/driver_exe -I./include/ driver.c -L./lib -l_romanops

lib_romanops.a: roman_ops.o
	ar rcs ./lib/lib_romanops.a ./obj/roman_ops.o
	ranlib ./lib/lib_romanops.a
roman_ops.o:
	gcc -c ./src/roman_ops.c -I./include -o ./obj/roman_ops.o
clean:
	rm -d ./obj/* ./bin/* ./lib/*

