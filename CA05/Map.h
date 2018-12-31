#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include "Flight.h"

class Map{
private:
public:
	
	std::vector<string> cities;
	std::vector<Flight *> flights;
	std::vector<vector<vector<Flight *>>> schedule;

	Map(string filename);
	list<Flight *> anypath(int start, int end);
	list<Flight *> fastpath(int start, int end);
	list<Flight> cheappath(int start, int end);
	void translate(list<Flight *> t);
	void printPath(list<Flight *> l);
	bool compare(Flight *n);
	int findCity(string n);
	int findPrice(list<Flight *> n);
	bool NodesRemain(vector<int> x);
};

#endif
