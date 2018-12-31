#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <list>
#include <string>
#include "Card.h"

using namespace std;

class Player{
private:
	string name;
	int gamesWon;

public:
	Player(string name, int games);
	Player(string player_file);
	list<Card> deck;
	string getName();
	int getGames();
	void setGames(int n);

};

#endif
