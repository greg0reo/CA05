all: Driver

Driver: Driver.o Tournament.o Player.o Card.o
	g++ Driver.o Tournament.o Player.o Card.o -o Driver.exe

Driver.o: Driver.cpp
	g++ -g -c Driver.cpp

Tournament.o: Tournament.cpp Tournament.h
	g++ -g -c Tournament.cpp

Player.o: Player.cpp Player.h
	g++ -g -c Player.cpp

Card.o: Card.cpp Card.h
	g++ -g -c Card.cpp

clean:
	rm -f *.o File.exe Log.txt

