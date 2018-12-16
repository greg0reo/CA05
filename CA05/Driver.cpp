#include "Flight.h"
#include "Map.h"
#include <iostream>
#include <string>
//#include <stoi>

using namespace std;

int main(int argc, char *argv[]){
	
	string place;
	cout << "Please input the .txt map file" << endl;
	cin >> place;
	Map Graph = Map(place);

	cout << "Please input where you're departing from" << endl;
	string d;
	cin >> d;

	cout << "Please input where you're going" << endl;
	string a;
	cin >> a;

	cout << "Would you like to take (1) any path or (2) fastest path?"  <<endl;
	int path;
	string pather;
	cin >> pather;
	path = stoi(pather);

	if(path == 1){
		Graph.translate(Graph.anypath(Graph.findCity(d), Graph.findCity(a)));
	}else{
		Graph.fastpath(Graph.findCity(d), Graph.findCity(a));
	}


	return 0;




}
