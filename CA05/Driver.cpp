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

	cout << "Here I am, and here I say" << endl;
//	cout << Graph.schedule[0][2][0]->arrive << endl;
//	cout << Graph.schedule[0][4][0]->arrive << endl;

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


	list<Flight *> thisThing;

	if(path == 1){
		thisThing = Graph.anypath(Graph.findCity(d), Graph.findCity(a));
//		Graph.translate(&Graph.anypath(Graph.findCity(d), Graph.findCity(a)));
//		cout << "do I get here?" << endl;
		Graph.translate(thisThing);
	}else{
		thisThing = Graph.fastpath(Graph.findCity(d), Graph.findCity(a));
	//	Graph.fastpath(Graph.findCity(d), Graph.findCity(a));
		Graph.translate(thisThing);
	}


	return 0;




}
