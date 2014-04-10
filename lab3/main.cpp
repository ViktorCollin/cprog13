#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

#include "character/user.h"

using namespace std;

void loadMap(){

}

void loadState(){

}

void storeState(){

}

void run(the_lion_king_saga::User &user){
	char c_input[256];
	string s_input;
	while(1){
		//user.list_actions();
		std::cin.getline (c_input,256);
		s_input = string(c_input);

		if(s_input == string("exit")) break;
		else{
			//Split
			istringstream buf(s_input);
			istream_iterator<string> beg(buf), end;
			vector<string> actions(beg, end);

			//DO cool stuff....
			if(actions.size() > 1)
				cout << actions[1] << endl;

		}
	}
	storeState();
}

int main(){
	the_lion_king_saga::User* simba = new the_lion_king_saga::User();
	loadMap();
	run(*simba);
	return 0;
}
