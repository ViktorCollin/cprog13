#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <map>

#include "character/user.h"
#include "environment/day.h"
#include "environment/environment.h"
#include "enums.cpp"

using namespace std;
using namespace the_lion_king_saga;

//Global variable declarations
static map<string, actions> mapActions;

//Metod declarations (no header file)
static void init();



std::shared_ptr<Environment> loadMap(){
	std::shared_ptr<Environment> day(new Day("day"));
#if DEBUG
	std::shared_ptr<Environment> day2(new Day("day2"));
	day->addNeighbor(day2, North);
	day2->addNeighbor(day, South);
	cout << day->description() << std::endl;
	cout << day2->description() << " mapsize " << day2->_neighbors.size() << endl;
	cout << day->getNeighbor(North)->description() << " mapsize " << day->getNeighbor(North)->_neighbors.size() << endl;
	cout << day2->getNeighbor(South)->description() << " mapsize " << day2->getNeighbor(South)->_neighbors.size() << endl;
	
#endif
	return day;
}

void loadState(){

}

void storeState(){

}

void needMoreParams(){
	cout << "Need another parameter" << endl;
}

void run(the_lion_king_saga::User &user){
	char c_input[256];
	string s_input;
	int running = 1;
	while(running){
		//user.list_actions();
		std::cin.getline (c_input,256);
		s_input = string(c_input);
		//Split
		istringstream buf(s_input);
		istream_iterator<string> beg(buf), end;
		vector<string> reply(beg, end);
		switch (mapActions[reply[0]]) {
			case Go :
				if(reply.size() > 1)
					user.go(reply[1]);
				else
					needMoreParams();
				break;
			case Look :
				if(reply.size() > 1)
					user.look(reply[1]);
				else
					needMoreParams();
				break;
			case Exit :
				running = 0;
				break;
			case Inventory:
				user.showInventory();
				break;
			case Fight :
				break;
			case Take :
				if(reply.size() > 1)
					user.take(reply[1]);
				else
					needMoreParams();
				break;
			case Drop :
				if(reply.size() > 1)
					user.drop(reply[1]);
				else
					needMoreParams();
				break;
			default:
				cout << "Unknown command" << endl;
		}
	}
	storeState();
}

int main(){
#if DEBUG
	std::cout << "In debug mode" << std::endl;
#endif
	init();
	std::shared_ptr<Environment> startposition = loadMap();
	the_lion_king_saga::User* simba = new the_lion_king_saga::User(startposition);
	run(*simba);
	return 0;
}

void init() {
	mapActions["Go"] = Go;
	mapActions["Look"] = Look;
	mapActions["Exit"] = Exit;
	mapActions["Fight"] = Fight;
	mapActions["Take"] = Take;
	mapActions["Drop"] = Drop;
	mapActions["Inventory"] = Inventory;
}
