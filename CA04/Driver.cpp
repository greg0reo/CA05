#include "Card.h"
#include "Player.h"
#include "Tournament.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(int argc, char *argv[]){

	vector<Player> People;
	People.push_back(Player( "Dude" , 0));
	People.push_back(Player( "I'm" , 0));
	People.push_back(Player( "Super" , 0));
	People.push_back(Player( "Shook" , 0));
	People.push_back(Player( "About" , 0));
	People.push_back(Player( "My" , 0));
	People.push_back(Player( "Grades" , 0));
	People.push_back(Player( "RN" , 0));



	Tournament theGame = Tournament(People);

	theGame.bracket(People);







}
