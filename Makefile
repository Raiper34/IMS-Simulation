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


clean:
	rm -f *.o simulator

.PHONY: clean
