# Description: Create client for SIP protokol
# File:        Makefile

CC              = g++
CFLAGS         = -g -lGLU -lGL -lglut
OBJ_FILES      = main.o areaCells.o cell.o
#LIBRARIES       = -static-libstdc++

all: simulator

run: experiment1 experiment2 experiment3 experiment4 experiment5 experiment6

simulator:	$(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@ $(CFLAGS)

main.o: main.cpp areaCells.h cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

areaCells.o: areaCells.cpp areaCells.h
	$(CC) -o $@ -c $<  $(CFLAGS)

cell.o: cell.cpp cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

experiment1:
	./simulator -v 2 -d 5 -t 100 -w 50 -r 10 -f experiment1

experiment2:
	./simulator -v 4 -d 5 -t 100 -w 50 -r 10 -f experiment2

experiment3:
	./simulator -v 2 -d 5 -t 100 -w 50 -r 10 -e 10 -f experiment3

experiment4:
	./simulator -v 2 -d 5 -t 100 -w 50 -e 10 -x 90 -m -f experiment4

experiment5:
	./simulator -d 5 -s 100 -t 100 -w 50 -r 20 -f experiment5

experiment6:
	./simulator -v 2 -d 5 -s 100 -t 100 -w 50 -r 10 -k -f experiment6

clean:
	rm -f *.o simulator experiment*

.PHONY: clean
