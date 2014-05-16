#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <map>

#include "character/user.h"
#include "character/cat.h"
#include "environment/day.h"
#include "enums.cpp"

using namespace the_lion_king_saga;


//Metod declarations (no header file)
static void init();



std::shared_ptr<Environment> loadMap(){
	std::shared_ptr<Environment> day(new Day("day"));
#if DEBUG
	std::shared_ptr<Environment> day2(new Day("day2"));
	day->addNeighbor(day2, North);
	day2->addNeighbor(day, South);
	std::cout << day->description() << std::endl;
	std::cout << day2->description() << " mapsize " << day2->_neighbors.size() << std::endl;
	std::cout << day->getNeighbor(North)->description() << " mapsize " << day->getNeighbor(North)->_neighbors.size() << std::endl;
	std::cout << day2->getNeighbor(South)->description() << " mapsize " << day2->getNeighbor(South)->_neighbors.size() << std::endl;
	
	std::unique_ptr<Animal> scar(new Cat("Scar", 100));	
	day2->addAnimal(std::move(scar));

#endif
	return day;
}

void loadState(){

}

void storeState(){

}

void needMoreParams(){
	std::cout << "Need another parameter" << std::endl;
}

void run(User &user){
	char c_input[256];
	std::string s_input;
	int running = 1;
	while(running){
		//user.list_actions();
		std::cin.getline(c_input,256);
		s_input = std::string(c_input);
		//Split
		std::istringstream buf(s_input);
		std::istream_iterator<std::string> beg(buf), end;
		std::vector<std::string> reply(beg, end);
		switch (strToAction(reply[0])) {
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
					user.look();
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
				std::cout << "Unknown command" << std::endl;
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
	User* simba = new User(startposition);
	run(*simba);
	return 0;
}

void init() {

}
