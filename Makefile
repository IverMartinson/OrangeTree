COMPILER=gcc
FLAGS_ALL=-g -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter
FLAGS_EXAMPLE=-Lbuilds/ -lorangetree -Wl,-rpath=builds/ -lm
FLAGS_LIB=-fPIC -shared -lc

main.bin: liborangetree.so
	$(COMPILER) $(FLAGS_ALL) src/launch\ program/main.c -o builds/main.bin $(FLAGS_EXAMPLE) 

liborangetree.so:
	$(COMPILER) $(FLAGS_ALL) src/main/main.c -o builds/liborangetree.so $(FLAGS_LIB) 

clean:
	rm builds/*
