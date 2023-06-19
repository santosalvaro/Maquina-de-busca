main: main.o maquinadebusca.o
	g++ main.o maquinadebusca.o -o main

main.o: main.cpp
	g++ -c main.cpp

maquinadebusca.o: maquinadebusca.h maquinadebusca.cpp
	g++ -std=c++17 -c maquinadebusca.cpp
	
clean:
	rm *.o main