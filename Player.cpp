#include "Player.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Player::Player(string name, int games){
	this->name = name;
	this->gamesWon = games;
}

Player::Player(string player_file){


}

string Player::getName(){
	return this->name;
}

int Player::getGames(){
	return this->gamesWon;
}

void Player::setGames(int n){
	this->gamesWon = n;
}


