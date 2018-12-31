#include "Card.h"

using namespace std;

Card::Card(int j, string k){
	this->n = j;
	this->f = k;
}

string Card::reader(){

	string ans;

	if(n == 2){
		ans += "Two ";
	}if(n == 3){
		ans += "Three ";
	}if(n == 4){
		ans += "Four ";
	}if(n == 5){
		ans += "Five ";
	}if(n == 6){
		ans += "Six ";
	}if(n == 7){
		ans += "Seven ";
	}if(n == 8){
		ans += "Eight ";
	}if(n == 9){
		ans += "Nine ";
	}if(n == 10){
		ans += "Ten ";
	}if(n == 11){
		ans += "Jack ";
	}if(n == 12){
		ans += "Queen ";
	}if(n == 13){
		ans += "King ";
	}if(n == 14){
		ans += "Ace ";
	}

	ans += "of ";

	if(f == "H"){
		ans += "Hearts";
	}if(f == "D"){
		ans += "Diamonds";
	}if(f == "C"){
		ans += "Clubs";
	}if(f == "S"){
		ans += "Spades";
	}

	return ans;

}
