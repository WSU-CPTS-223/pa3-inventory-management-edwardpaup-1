out: clean compile execute

compile: main.cpp
	g++ -g -Wall -std=c++11 main.cpp MurmurHash3.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe