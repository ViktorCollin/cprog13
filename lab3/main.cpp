#include <iostream>

using namespace std;

void loadMap(){

}

void loadState(){

}

void run(){
	int action;
	while(1){
		cin >> action;
		cout << action << endl;

		if(action == 0) break;
		else{
			//handle actions here;
		}
	}
}

int main(){
	loadMap();
	run();
	return 0;
}
