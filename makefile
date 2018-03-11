project1: main.o LispList.o
	g++ -std=c++11 -o project1 main.o LispList.o

main.o: main.cpp LispList.h
	g++ -std=c++11 -c main.cpp

LispList.o: LispList.cpp LispList.h
	g++ -std=c++11 -c LispList.cpp

clean:
	rm project1 main.o LispList.o
