#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>

using namespace std;

class Flight{
	private:

	public:
		std::string from;
		std::string to;
		int depart;
		int arrive;
		int price;

		Flight(string f, string t, string d, string a, string p);
		
};

#endif
