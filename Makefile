# Description: Create client for SIP protokol
# File:        Makefile

CC              = g++
CFLAGS         = -g -lGLU -lGL -lglut
OBJ_FILES      = main.o areaCells.o cell.o
#LIBRARIES       = -static-libstdc++

all: simulator

run: fig6A fig6B fig7A fig7B fig8

simulator:	$(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@ $(CFLAGS)

main.o: main.cpp areaCells.h cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

areaCells.o: areaCells.cpp areaCells.h
	$(CC) -o $@ -c $<  $(CFLAGS)

cell.o: cell.cpp cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

experiment1:
	./simulator -v 2 -d 5 -s 100 -t 100 -w 50 -r 10 -f experiment1

experiment2:
	./simulator -v 4 -d 5 -s 100 -t 100 -w 50 -r 10 -f experiment1

obrazok7A:
	./simulator -v 2 -d 5 -s 1 -t 5 -w 11 -g -f fig7A

obrazok7B:
	./simulator -v 4 -d 5 -s 1 -t 7 -w 11 -g -f fig7B

experiment3:
	./simulator -v 2 -d 5 -s 100 -t 100 -w 50 -r 10 -e 10 -f experiment3

clean:
	rm -f *.o simulator fig*

.PHONY: clean
