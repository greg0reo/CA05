#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <list>
include "Flight.h"

class Map{
private:
	std::vector<string> cities;
	std::vector<Flight> flights
	std::vector<Flight> schedule[][];

public:
	Map(string filename);
	list<Flight> fastpath(int start, int end);
	list<Flight> cheappath(int start, int end);
	void printPath(list<Flight> l);
	bool compare(Flight n);
	int findCity(string n);
};