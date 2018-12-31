#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

using namespace std;

class Card{
public:
	int n;
	std::string f;
	Card(int j, string k);
	bool operator < (Card const &obj){
		if(n < obj.n){ return true;} else {return false;}
	}
	bool operator == (Card const &obj){
		if(n == obj.n){return true;} else {return false;}
	}

};

#endif
