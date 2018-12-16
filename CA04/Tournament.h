#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>

#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include "Player.h"
#include "Card.h"

class Tournament{
private:
	vector<Player> players;
	int numMatches;
	int highBattles;
	int totalBattles;
	int avgBattles;
	string log_file;

public:
	Tournament(vector<Players> input);
	Tournament(string player_file, string log_file);
	Player bracket(vector<Players> input);
	Player war(Player one, Player two);
	void log(string logThis, string log_file);
	
	//GETTER and SETTER functions
	void setNum(int n);
	int getNum();
	void setHigh(int n);
	int getHigh();
	void setTotal(int n);
	int getTotal();
	void setAvg(int n);
	int getAvg();
	string getLog();

};



