.PHONY: number caesar bars point

number:
	g++ ./solutions/number.cpp -o ./main.o -std=c++11 && ./main.o

caesar:
	g++ ./solutions/caesar.cpp -o ./main.o -std=c++11 && ./main.o

bars:
	g++ ./solutions/bars.cpp -o ./main.o -std=c++11 && ./main.o

point:
	g++ ./solutions/point.cpp -o ./main.o -std=c++11 && ./main.o
