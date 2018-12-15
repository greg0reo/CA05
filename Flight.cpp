#include "Flight.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Flight::Flight(string f, string t, string d, string a, string p){
	this->from = f;
	this->to = t;

	int i = 1;
	for (char& c : d){
		if(i == 1){
			this->depart += (1000 * (c - '0'));
		}
		if(i == 2){
			this->depart += (100 * (c - '0'));
		}
		if(i == 4){
			this->depart += (10 * (c - '0'));
		}
		if(i == 5){
			this->depart += (c - '0');
		}
		if(i == 6 || c == 'p'){
			this->depart += 1200;
		}
		i++;
	}

	i = 1;
	for (char& c : a){
		if(i == 1){
			this->arrive += (1000 * (c - '0'));
		}
		if(i == 2){
			this->arrive += (100 * (c - '0'));
		}
		if(i == 4){
			this->arrive += (10 * (c - '0'));
		}
		if(i == 5){
			this->arrive += (c - '0');
		}
		if(i == 6 || c == 'p'){
			this->arrive += 1200;
		}
		i++;
	}

	i = 1;
	string p2;
	
	p = p.substr(1, p.size()-1);

	/*for (char& c : p){
		if(i!=1){
			p2.append(c*);
		}
	i++;
	}*/
	this->price = stof(p);

}
