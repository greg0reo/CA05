#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

class Card{
public:
	int n;
	string f;
	Card(int j, string k);
	Card operator < (Card const &obj){
		if(n < obj.n){ return true;} else {return false;}
	}
	Card operator == (Card const &obj){
		if(n == obj.n){return true;} else {return false;}
	}

};