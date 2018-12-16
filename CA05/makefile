all: Driver

Driver: Driver.o Flight.o Map.o
	g++ Driver.o Flight.o Map.o -o Driver.exe

Driver.o: Driver.cpp
	g++ -g -c Driver.cpp

Flight.o: Flight.cpp Flight.h
	g++ -g -c Flight.cpp

Map.o: Map.cpp Map.h
	g++ -g -c Map.cpp

clean:
	rm -f *.o File.exe
