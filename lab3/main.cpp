#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <map>

#include "character/user.h"
#include "character/friend.h"
#include "environment/day.h"
#include "environment/night.h"
#include "environment/djungle.h"
#include "enums.cpp"

using namespace the_lion_king_saga;

std::vector<std::unique_ptr<Environment>> _map;
//Metod declarations (no header file) 
static void init();



Environment* loadMap(){
#if FILE
    std::string line;
    std::ifstream mapFile("map.txt");
    if (mapFile.is_open()){
        while(getline(mapFile, line)){
            std::cout << line << std::endl;
        }
        mapFile.close();
    } else {
        return NULL;
    }
#else
    std::unique_ptr<Environment> prideLands(new Day("Pride lands", "Home sweet home", "lies the kingdom of the pride lands"));
    std::unique_ptr<Environment> scarsPlace(new Night("Scars place", "You find your self in the shadows of the lion cliff, it is a spoky place to stay", "is a shadowy place where uncle scar lives"));
    std::unique_ptr<Environment> waterHole(new Day("The water hole", "You are on the your way to the water hole, but the plan is to reach the elephant graveyard. If you just could get rid of that stupid bird Zazu.", "lies the water hole"));
    std::unique_ptr<Environment> elephantGraveyard(new Night("The elephant graveyard", "you have arived at the scariest place in the world, the elephat graveyard. Ther is a lot of elephant skulls with large dark holes where the eyes used to be.", "lies the big dark elephant graveyard"));
    std::unique_ptr<Environment> djungle(new Djungle("Djungle", "The big lush djungle", "lies the djungle"));
    std::unique_ptr<Environment> djungle2(new Night("Djungle", "The night has fallen over the djungle", "lies the djungle"));
    std::unique_ptr<Environment> prideLands2(new Night("Pride lands", "This is what use to be your home", "lies the kingdom of the pride lands"));
    
    prideLands->addNeighbor(scarsPlace.get(), West);
    scarsPlace->addNeighbor(prideLands.get(), East);
    prideLands->addNeighbor(waterHole.get(), North);
    waterHole->addNeighbor(prideLands.get(), South);
    waterHole->addNeighbor(elephantGraveyard.get(), North);
    
    djungle->addNeighbor(djungle.get(), North);
    djungle->addNeighbor(djungle.get(), South);
    djungle->addNeighbor(djungle.get(), East);
    djungle->addNeighbor(djungle.get(), West);

    std::unique_ptr<Animal> mufasa(new Friend("Mufasa", 100, 
    "Mufasa:\tEverything you see exists together in a delicate balance.\n\tAs king, you need to understand that balance and respect all the creatures,\n\tfrom the crawling ant to the leaping antelope.\nSimba:\tBut, Dad, don't we eat the antelope?\nMufasa:\tYes, Simba, but let me explain.\n\tWhen we die, our bodies become the grass, and the antelope eat the grass.\n\tAnd so we are all connnected in the great Circle of Life."));
    
    prideLands->addAnimal(std::move(mufasa));
    Environment* start = prideLands.get();
    _map.push_back(std::move(prideLands));


    return start;
#endif
}

void storeMap(User &user){
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
            case Talk :
                if(reply.size() > 1)
                    user.talk_to(reply[1]);
                else
                    std::cout << user.getSpeach() << std::endl;
                break;
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
}

int main(){
#if DEBUG
    std::cout << "In debug mode" << std::endl;
#endif
    init();
    Environment* startposition = loadMap();
    if(startposition == NULL) {
        std::cout << "Unable to open map, Exiting the game!" << std::endl; 
        return 1;
    }
    User* simba = new User(startposition);
    run(*simba);
    storeMap(*simba);
    delete simba;
    return 0;
}

void init() {

}
