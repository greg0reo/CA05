#include "Tournament.h"

using namespace std;

Tournament::Tournament(vector<Players> input){
	this->players = input;
}

Tournament::Tournament(string player_file, string log_file){

}

Player Tournament::bracket(vector<Players> input){
	if(input.size() == 2){
		return war(input[0], input[1]);
	}else{
		vector<Players> one;
		vector<Players> two;
		for(i= 0, i < input.size(), i+= 2){
			one.push_back(input[i]);
			two.push_back(input[i+1]);
		}
		war(bracket(one), bracket(two));
	}
}

Player Tournament::war(Player one, Player two){
	int battle = 0;
	int war = 0;
	Card randDeck[] = {Card(2, "H"), Card(2, "D"), Card(2, "S"), Card(2, "C"),
				Card(3 , "H"), Card(3 , "D"), Card( 3, "S"), Card( 3, "C"),
				Card(4 , "H"), Card(4 , "D"), Card( 4, "S"), Card( 4, "C"),
				Card(5 , "H"), Card(5 , "D"), Card( 5, "S"), Card( 5, "C"),
				Card(6 , "H"), Card(6 , "D"), Card( 6, "S"), Card( 6, "C"),
				Card(7 , "H"), Card(7 , "D"), Card( 7, "S"), Card( 7, "C"),
				Card(8 , "H"), Card(8 , "D"), Card( 8, "S"), Card( 8, "C"),
				Card(9 , "H"), Card(9 , "D"), Card( 9, "S"), Card( 9, "C"),
				Card(10 , "H"), Card(10 , "D"), Card( 10, "S"), Card( 10, "C"),
				Card(11 , "H"), Card(11 , "D"), Card( 11, "S"), Card( 11, "C"),
				Card(12 , "H"), Card(12 , "D"), Card( 12, "S"), Card( 12, "C"),
				Card(13 , "H"), Card(13 , "D"), Card( 13, "S"), Card( 13, "C"),
				Card(14 , "H"), Card(14 , "D"), Card( 14, "S"), Card( 14, "C")};
	unsigned seed = 0;
	shuffle(randDeck.begin(), randDeck.end(), default_random_engine(seed));
	for(i = 0, i < 52, i += 2){
		one.deck.push_front( randDeck[i]);
		two.deck.push_front( randDeck[i+1]);
	}
	// Now the fight can begin!
	vector<Card> temp;
	while(one.deck.size() != 0 && two.deck.size() != 0){
		//WAR!!
		if(one.deck.front() == two.deck.front()){
			if(one.deck.size() == 1) {
				one.deck.pop_front();
				break;
			}
			if(two.deck.size() == 1) {
				two.deck.pop_front();
				break;
			}
			for(i = 0; i < 4; i++){
				if(one.deck.size() > 1){
					temp.push_back(one.deck.front());
					one.deck.pop_front();
				}
				if(two.deck.size() > 1){
					temp.push_back(two.deck.front());
					two.deck.pop_front();
				}
			}
			// TWO WINS WAR
			if(one.deck.front() < two.deck.front()){ 
				temp.push_back(one.deck.front());
				temp.push_back(two.deck.front());
				one.deck.pop_front();
				two.deck.pop_front();
				//LOG
				for(const Card& i : temp){
					two.deck.push_back(i);
				}
			// ONE WINS WAR
			}else{
				temp.push_back(one.deck.front());
				temp.push_back(two.deck.front());
				one.deck.pop_front();
				two.deck.pop_front();
				//LOG				
				for(const Card& i : temp){
					one.deck.push_back(i);
				}
			}


		// TWO WINS
		}elseif(one.deck.front() < two.deck.front()){
			temp.push_back(one.deck.front());
			temp.push_back(two.deck.front());
			one.deck.pop_front();
			two.deck.pop_front();	
			//LOG		
			
			for(const Card& i : temp){
				two.deck.push_back(i);
			}
		// ONE WINS
		}else{
			temp.push_back(one.deck.front());
			temp.push_back(two.deck.front());
			one.deck.pop_front();
			two.deck.pop_front();
			//LOG
			
			for(const Card& i : temp){
				one.deck.push_back(i);
			}
		}

		temp.clear();

	}


	//update data
	if(one.)



	if(one.deck.size()==0){
		// TWO WINS
		//LOG
		two.setGames( two.getGames()+1);
		return two;
	}else{
		//ONE WINS
		//LOG
		one.setGames( one.getGames()+1);
		return one;
	}

}
