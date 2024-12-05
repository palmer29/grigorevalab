.PHONY: build clean

CFLAGS = -c -Wall
SOURCE_M = main.c 
SOURCE_C = cmdcalc.c

build: $(SOURCE_C) $(SOURCE_M) 
	gcc $(SOURCE_C) $(SOURCE_M) -o calc

test: calc
	valgrind ./calc 8 '*' 8 8 - 6 -k 3

clean:
	rm calc
