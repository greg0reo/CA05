#include "Map.h"
#include "Flight.h"
#include <climits>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

Map::Map(string filename){
	fstream file(filename);
	if(!file) return;
	string line;
	//vector<string> path;

	//cout << "file taken" << endl;

	vector<string> path;
	string temp;
//	Flight temp2("", "", "", "", "");
	while(getline(file, line)){
		path.resize(0);
		//vector<string> path;
		istringstream iss(line);
		for(string s; iss >> s;){
			temp = s;
			//cout << temp << endl;
			path.push_back(temp);
			//cout << path.back() << endl;
		}
		//cout << "\n" << endl;
		flights.push_back(new Flight(path[0], path[1], path[2], path[3], path[4]));
		
		//temp2 = Flight(path[0], path[1], path[2], path[3], path[4]);
//		cout << path[0] << path[2] << endl;
		
		//flights.push_back(temp2);
//		cout << flights.back()->from << flights.back()->depart << endl;

		path[0] = "";
		path[1] = "";
		path[2] = "";
		path[3] = "";
		path[4] = "";
		
	}
	
	//cout << "\n\n\n" << endl;

	//cout << "Flights" << endl;
	
	//Sets up key
	for(auto n : flights){
		if(compare(n)){
			cities.push_back(n->from);
		}
	}

//	cout << "Key" << endl;

	//Sets up matrix
	//schedule[cities.size()][cities.size()];
	schedule.resize(cities.size());
	for(int i = 0; i < cities.size(); i++){
		schedule[i].resize(cities.size());
	}
	for(auto x : flights){
//		cout << "1" << endl;
//		schedule.at(findCity(x.from)).at(findCity(x.to)).push_back(x);
		schedule[findCity(x->from)][findCity(x->to)].push_back(x);
//		cout << "2" << endl;
	}
//	cout << "Map" << endl;
//	cout << findCity("Yonkers") << cities[findCity("Yonkers")] << endl;


}

bool Map::compare(Flight *n){
	for(string x : cities){
		if(n->from == x){
			return false;
		}
	}
	return true;
}

int Map::findCity(string n){
	for(int i = 0; i < cities.size(); i++){
		if(n == cities[i]){
//			cout << "city found" << endl;
			return i;
		}
	}
	return 0;
}


list<Flight *> Map::anypath(int start, int end){
//	cout << "anypath" << endl;
	vector<int> shortestTime;
	vector<int> visitedNodes;
	vector<Flight *> prevFlight;
	int length;
	for(int i = 0; i < cities.size(); i++){
		if(i == start){
			shortestTime.push_back(0);
			visitedNodes.push_back(2);
		}else{
			shortestTime.push_back(INT_MAX);
			visitedNodes.push_back(0);
		}
		length = i;
		//prevFlight.push_back(NULL);
		prevFlight.push_back(new Flight(cities[start], cities[i], "999999", "999999", "999999"));
	}
	//prevFlight.resize(length);
//	cout << start << endl;
//	cout << end << endl;

	for(int i = 0; i < cities.size() ; i++){
		int earliest = INT_MAX;
		for(int j = 0; j < schedule[start][i].size(); j++){
			if(schedule[start][i].at(j)->arrive < earliest){

//  				cout << schedule[start][i].at(j)->from << schedule[start][i].at(j)->depart << schedule[start][i].at(j)->to << schedule[start][i].at(j)->arrive << endl;
//				cout << start << cities[start] <<endl;
//				cout << i << " i"<< endl;
//				cout << findCity("Yonkers") << cities[findCity("Yonkers")] << endl;
				earliest = schedule[start][i].at(j)->arrive;
				shortestTime[i] = earliest;
				prevFlight[i] = schedule[start][i].at(j);
//				cout << i << endl;
//				cout << prevFlight[i]->from << prevFlight[i]->depart << " -> " << prevFlight[i]->to << prevFlight[i]->arrive << endl;
//				cout << "1111111" << endl;
//				cout << prevFlight[i]->to << endl;
//				cout << prevFlight[i]->arrive << endl; //Testing time
//				cout << "\n" << endl;

				visitedNodes[i] = 1;
//				cout << i << endl;
			}
		}
	}
//	visitedNodes[start] = true;
	
//	cout << "Behind second for loop" <<endl;

	for(int i=0; i < cities.size() ; i++){
//		cout << cities[i] << endl;
	}

//	cout << "\n" << endl;

	while(NodesRemain(visitedNodes)){
		int closest;
		int distance = INT_MAX;
		for(int i = 0; i < cities.size(); i++){
			if(visitedNodes[i] == 1 && shortestTime[i] < distance){
				closest = i;
				distance = shortestTime[i];

			}
		}


//		cout << cities[closest] << endl; // checks the order the cities are discovered in


		int arrivalTime = prevFlight[closest]->arrive;
		visitedNodes[closest] = 2;
//		cout << cities[closest] << "\n" << endl;

		for(int i = 0; i < cities.size(); i++){
			int earliest = shortestTime[i];
			for(int j = 0; j < schedule[closest][i].size(); j++){
				//int earliest = shortestTime[i];

 // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				if(schedule[closest][i].at(j)->arrive < earliest && arrivalTime < schedule[closest][i].at(j)->depart){  // || schedule[closest][i].at(j).depart > arrivalTime){
					earliest = schedule[closest][i].at(j)->arrive;
					shortestTime[i] = earliest;
					prevFlight[i] = schedule[closest][i].at(j);
//					cout << prevFlight[i]->from << prevFlight[i]->depart << " -> " << prevFlight[i]->to << prevFlight[i]->arrive << endl;
					visitedNodes[i] = 1;
					//visitedNodes[i] = false;
				}
			}
		}

	}

//	cout << "After massive while loop" <<endl;
	// RETURN VALUE

	list<Flight *> answer;
	answer.push_front(prevFlight[end]);
	int g;
	int greg = 0;
	while(findCity(answer.front()->from) != start){
//		cout << "\n" << endl;
//		cout << cities[g] <<endl;
		g = findCity(answer.front()->from);
//		cout << cities[g] << endl;
		answer.push_front(prevFlight[g]);
//		cout << prevFlight[g]->from << "\n" << endl;
//		greg++;
//		if(greg == 100){
//			break;
//		}
//		cout << "stuck here for ever" << endl;
	}
	
	return answer;
	// FIGURE OUT RETURN VALUE


}

list<Flight *> Map::fastpath(int start, int end){
	
list<Flight *> Map::anypath(int start, int end){
//	cout << "anypath" << endl;
	vector<int> shortestTime;
	vector<int> visitedNodes;
	vector<Flight *> prevFlight;
	int length;
	for(int i = 0; i < cities.size(); i++){
		if(i == start){
			shortestTime.push_back(0);
			visitedNodes.push_back(2);
		}else{
			shortestTime.push_back(INT_MAX);
			visitedNodes.push_back(0);
		}
		length = i;
		//prevFlight.push_back(NULL);
		prevFlight.push_back(new Flight(cities[start], cities[i], "999999", "999999", "999999"));
	}
	//prevFlight.resize(length);
//	cout << start << endl;
//	cout << end << endl;

	for(int i = 0; i < cities.size() ; i++){
		int earliest = INT_MAX;
		for(int j = 0; j < schedule[start][i].size(); j++){
			if(schedule[start][i].at(j)->arrive < earliest){

//  				cout << schedule[start][i].at(j)->from << schedule[start][i].at(j)->depart << schedule[start][i].at(j)->to << schedule[start][i].at(j)->arrive << endl;
//				cout << start << cities[start] <<endl;
//				cout << i << " i"<< endl;
//				cout << findCity("Yonkers") << cities[findCity("Yonkers")] << endl;
				earliest = schedule[start][i].at(j)->arrive;
				shortestTime[i] = earliest;
				prevFlight[i] = schedule[start][i].at(j);
//				cout << i << endl;
//				cout << prevFlight[i]->from << prevFlight[i]->depart << " -> " << prevFlight[i]->to << prevFlight[i]->arrive << endl;
//				cout << "1111111" << endl;
//				cout << prevFlight[i]->to << endl;
//				cout << prevFlight[i]->arrive << endl; //Testing time
//				cout << "\n" << endl;

				visitedNodes[i] = 1;
//				cout << i << endl;
			}
		}
	}
	visitedNodes[start] = 1;
	
//	cout << "Behind second for loop" <<endl;

	for(int i=0; i < cities.size() ; i++){
//		cout << cities[i] << endl;
	}

//	cout << "\n" << endl;

	while(NodesRemain(visitedNodes)){
		int closest;
		int distance = INT_MAX;
		for(int i = 0; i < cities.size(); i++){
			if(visitedNodes[i] == 1 && shortestTime[i] < distance){
				closest = i;
				distance = shortestTime[i];

			}
		}


//		cout << cities[closest] << endl; // checks the order the cities are discovered in


		int arrivalTime = prevFlight[closest]->arrive;
		visitedNodes[closest] = 2;
//		cout << cities[closest] << "\n" << endl;

		for(int i = 0; i < cities.size(); i++){
			int earliest = shortestTime[i];
			for(int j = 0; j < schedule[closest][i].size(); j++){
				//int earliest = shortestTime[i];

 // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				if(schedule[closest][i].at(j)->arrive < earliest && arrivalTime < schedule[closest][i].at(j)->depart){  // || schedule[closest][i].at(j).depart > arrivalTime){
					earliest = schedule[closest][i].at(j)->arrive;
					shortestTime[i] = earliest;
					prevFlight[i] = schedule[closest][i].at(j);
//					cout << prevFlight[i]->from << prevFlight[i]->depart << " -> " << prevFlight[i]->to << prevFlight[i]->arrive << endl;
					visitedNodes[i] = 1;
					//visitedNodes[i] = false;
				}
			}
		}

	}

//	cout << "After massive while loop" <<endl;
	// RETURN VALUE

	list<Flight *> answer;
	answer.push_front(prevFlight[end]);
	int g;
	int greg = 0;
	while(findCity(answer.front()->from) != start){
//		cout << "\n" << endl;
//		cout << cities[g] <<endl;
		g = findCity(answer.front()->from);
//		cout << cities[g] << endl;
		answer.push_front(prevFlight[g]);
//		cout << prevFlight[g]->from << "\n" << endl;
//		greg++;
//		if(greg == 100){
//			break;
//		}
//		cout << "stuck here for ever" << endl;
	}
	
	return answer;
	// FIGURE OUT RETURN VALUE


}

	
	
	
	
	
	
	
/*	vector<int> shortestTime;
	vector<bool> visitedNodes;
	vector<Flight> prevFlight;
	int length;
	for(int i = 0; i < cities.size(); i++){
		if(i == start){
			shortestTime.push_back(0);
			visitedNodes.push_back(true);
		}else{
			shortestTime.push_back(INT_MAX);
			visitedNodes.push_back(false);
		}
		length = i;
		//prevFlight.push_back(NULL);
		prevFlight.push_back(Flight(cities[start], cities[i], "999999", "999999", "999999"));
	}
	//prevFlight.resize(length);

	for(int i = 0; i < cities.size() ; i++){
		int earliest = INT_MAX;
		for(int j = 0; j < schedule[start][i].size(); j++){
			if(schedule[start][i].at(j).arrive < earliest){
				earliest = schedule[start][i].at(j).arrive;
				shortestTime[i] = earliest;
				prevFlight[i] = schedule[start][i].at(j);
			}
		}
	}
	visitedNodes[start] = true;

	while(NodesRemain(visitedNodes)){
		int closest;
		int distance = INT_MAX;
		for(int i = 0; i < cities.size(); i++){
			if(visitedNodes[i] == false || shortestTime[i] < distance){
				closest = i;
				distance = shortestTime[i];
			}
		}

		int arrivalTime = prevFlight[closest].arrive;
		for(int i = 0; i < cities.size(); i++){
			for(int j = 0; j < schedule[closest][i].size(); j++){
				int earliest = shortestTime[i];
				if(schedule[closest][i].at(j).arrive < earliest || schedule[closest][i].at(j).depart > arrivalTime){
					earliest = schedule[closest][i].at(j).arrive;
					shortestTime[i] = earliest;
					prevFlight[i] = schedule[closest][i].at(j);
					visitedNodes[i] = false;
				}
			}
		}

	}

	// RETURN VALUE

	list<Flight> answer;
	answer.push_front(prevFlight[end]);
	int g;
	while(findCity(answer.front().from) != start){
		g = findCity(answer.front().from);
		answer.push_front(prevFlight[g]);
	}

	return answer;
	// FIGURE OUT RETURN VALUE
*/
}

void Map::translate(list<Flight *> t){
	int totalcost;
	int starttime;
	int endtime;
	totalcost = findPrice(t);
	if(totalcost >= 99999){
		cout << "There are no flights to your destination" << endl;
	}else{
		cout << "The flights you will take are: " << endl;
		for(auto i : t){
			cout << i->from << " (" << i->depart <<  ") -> " << i->to << " (" << i->arrive << ")  $" << i->price << "\n" << endl;
			//totalcost += i->price;
		}
		//totalcost = findPrice(t);
		cout << "total price: " << endl;
		cout << totalcost << endl;
	}
}


bool Map::NodesRemain(vector<int> x){
	for(int i : x){
		if(i == 1){
			return true;
		}
	}
	return false;
}



list<Flight> Map::cheappath(int start, int end){
	list<Flight> path;
	vector<int> colorCode;



}


int Map::findPrice(list<Flight *> n){
	int sum= 0;
	for(auto i : n){
		sum += i->price;
	}
	return sum;
}
