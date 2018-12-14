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

	while(getline(file, line)){
		vector<string> path;
		istringstream iss(line);
		for(string s; iss >> s;){
			path.push_back(s);
		}
		flights.push_back(Flight(path[0], path[1], path[2], path[3], path[4]));
	}

	//Sets up key
	for(Flight n : flights){
		if(compare(n)){
			cities.push_back(n.from);
		}
	}

	//Sets up matrix
	schedule[cities.size()][cities.size()];
	for(Flight x : flights){
		schedule[findCity(x.from)][findCity(x.to)].push_back(x);
	}

}

bool Map::compare(Flight n){
	for(string x : cities){
		if(n.from == x){
			return false;
		}
	}
	return true;
}

int Map::findCity(string n){
	for(int i = 0; i < cities.size(); i++){
		if(n == cities[i]){
			return i;
		}
	}
	return 0;
}


list<Flight> Map::anypath(int start, int end){
vector<int> shortestTime;
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
	}
	prevFlight.resize(length);

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
					//visitedNodes[i] = false;
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


}

list<Flight> Map::fastpath(int start, int end){
	vector<int> shortestTime;
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
	}
	prevFlight.resize(length);

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

}

void Map::translate(list<Flight> t){
	int totalcost;
	int starttime;
	int endtime;
	cout << "The flights you will take are: " << endl;
	for(Flight i : t){
		cout << i.from << endl;
		cout << " (" << endl;
		cout << i.depart << endl;
		cout << ") -> " << endl;
		cout << i.to << endl;
		cout << " (" << endl;
		cout << i.arrive << endl;
		cout << ")  $" << endl;
		cout << i.price << endl;
		cout << "\n" << endl;
		totalcost += i.price;
	}
	cout << "total price: " << endl;
	cout << totalcost << endl;
}


bool Map::NodesRemain(vector<bool> x){
	for(bool i : x){
		if(i == false){
			return true;
		}
	}
	return false;
}



list<Flight> Map::cheappath(int start, int end){
	list<Flight> path;
	vector<int> colorCode;



}


int Map::findPrice(list<Flight> n){
	int sum= 0;
	for(Flight i : n){
		sum += i.price;
	}
	return sum;
}
