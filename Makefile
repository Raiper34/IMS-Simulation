# Description: Create client for SIP protokol
# File:        Makefile

CC              = g++
CFLAGS         = -g -lGLU -lGL -lglut
OBJ_FILES      = main.o areaCells.o cell.o
#LIBRARIES       = -static-libstdc++

all: simulator

simulator:	$(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@ $(CFLAGS)

main.o: main.cpp areaCells.h cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

areaCells.o: areaCells.cpp areaCells.h
	$(CC) -o $@ -c $<  $(CFLAGS)

cell.o: cell.cpp cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

fig6A:
	./simulator -v 2 -d 5 -s 10 -t 100 -w 50 -r 10 -g -f fig6A

fig6B:
	./simulator -v 4 -d 5 -s 10 -t 100 -w 50 -r 10 -g -f fig6B

fig8:
	./simulator -v 4 -d 5 -s 10 -t 100 -w 50 -r 10 -e 10 -g -f fig8

clean:
	rm -f *.o simulator

.PHONY: clean
