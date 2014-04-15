#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <map>

#include "character/user.h"
#include "environment/day.h"
#include "environment/environment.h"

#define DEBUG 1


using namespace std;

enum actions{
	Go = 1,
	Look = 2,
	Exit = 3,
	Fight = 4,
	Take = 5,
	Drop = 6
};

static map<string, actions> mapActions;



static void init();

the_lion_king_saga::Environment* loadMap(){
	the_lion_king_saga::Environment *day = new the_lion_king_saga::Day();
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
			case Fight :
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
	init();
	the_lion_king_saga::Environment* startposition = loadMap();
	the_lion_king_saga::User* simba = new the_lion_king_saga::User(*startposition);
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
}
