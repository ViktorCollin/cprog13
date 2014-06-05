#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
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
    std::string line;
    std::ifstream mapFile("map.txt");
    if (mapFile.is_open()){
        while(getline(mapFile, line)){
            std::cout << line << std::endl;
        }
        mapFile.close();
    } else {
#if DEBUG == 0
        return NULL;
#endif
    }
    std::shared_ptr<Environment> day(new Day("day", "The green grass", "lies the green grass"));

#if DEBUG
    std::shared_ptr<Environment> day2(new Day("day2", "The big prairie", "you see the big prairie"));
    day->addNeighbor(day2, North);
    day2->addNeighbor(day, South);
    day->addNeighbor(day, West);

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
        std::cout << std::endl;
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
            case Cheeks:
                user.showInventory();
                break;
            case Fight :
                if(reply.size() > 1)
                    user.fight(reply[1]);
                else
                    needMoreParams();
                break;
            case Take :
                if(reply.size() > 1)
                    user.take(reply[1]);
                else
                    needMoreParams();
                break;
            case Use :
                if(reply.size() > 1)
                    user.use(reply[1]);
                else
                    needMoreParams();
                break;
            case Drop :
                if(reply.size() > 1)
                    user.drop(reply[1]);
                else
                    needMoreParams();
                break;
            case Help:
                printHelpMsg();
                break;
            default:
                std::cout << "Unknown command, write 'Help' for more information about what you can do" << std::endl;
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
    if(startposition == NULL) {
        std::cout << "Unable to open map, Exiting the game!" << std::endl; 
        return 1;
    }
    User* simba = new User(startposition);
    run(*simba);
    return 0;
}

void init() {

}
