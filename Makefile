all:		main

main:	main.cpp
		g++ -std=c++11 main.cpp -o main

clean:
	rm -fr main