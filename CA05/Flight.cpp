#include "Flight.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Flight::Flight(string f, string t, string d, string a, string p){
	this->from = f;
	this->to = t;

	// In this part, I store the time as an integer in military time
	// since I never do any operations (besides comparing) on the time, this is ok
	this->depart = 0;
	this->depart += (((d.at(0)) - '0') * 1000);
	this->depart += (((d.at(1)) - '0') * 100);
	this->depart += (((d.at(3)) - '0') * 10);
	this->depart += ((d.at(4)) - '0');
	if( (d.at(5)) == 'p' && d.at(0) == '1' && d.at(1) == '2'){
//		this->depart += 1200;
	}else if( d.at(5) == 'p'){
		this->depart += 1200;
	}else if( d.at(5) == 'a' && d.at(0) == '1' && d.at(1) == '2'){
		this->depart -= 1200;
	}

	int i = 1;
/*	for (char& c : d){
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
*/

	this->arrive = 0;
	this->arrive += (((a.at(0)) - '0') * 1000);
	this->arrive += (((a.at(1)) - '0') * 100);
	this->arrive += (((a.at(3)) - '0') * 10);
	this->arrive += ((a.at(4)) - '0');
	if( (a.at(5)) == 'p' && a.at(0)=='1' && a.at(1)=='2'){
//		this->arrive += 1200;
	}else if( a.at(5) == 'p'){
		this->arrive += 1200;
	}else if( a.at(5) == 'a' && a.at(0) == '1' && a.at(1) == '2'){
		this->arrive -= 1200;
	}

/*


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
*/
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
