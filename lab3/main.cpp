#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <map>

#include "character/user.h"
#include "character/friend.h"
#include "character/enemy.h"
#include "environment/day.h"
#include "environment/night.h"
#include "environment/djungle.h"
#include "enums.cpp"

using namespace the_lion_king_saga;

User* user;
std::vector<std::unique_ptr<Environment>> _map;
int level;
//Metod declarations (no header file) 
static void init();
void updateProgress(std::string);



Environment* loadMap(){
#ifdef FILE
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
    //waterHole->addNeighbor(elephantGraveyard.get(), North);
    
    djungle->addNeighbor(djungle.get(), North);
    djungle->addNeighbor(djungle.get(), South);
    djungle->addNeighbor(djungle.get(), East);
    djungle->addNeighbor(djungle.get(), West);

    std::unique_ptr<Animal> mufasa(new Friend("Mufasa", 100, 
    "Mufasa:\tEverything you see exists together in a delicate balance.\n\tAs king, you need to understand that balance and respect all the creatures,\n\tfrom the crawling ant to the leaping antelope.\nSimba:\tBut, Dad, don't we eat the antelope?\nMufasa:\tYes, Simba, but let me explain.\n\tWhen we die, our bodies become the grass, and the antelope eat the grass.\n\tAnd so we are all connnected in the great Circle of Life.\n\tYou are NOT allowed to go to the areas the sun dont reach."));
    std::unique_ptr<Animal> scar(new Friend("Scar", 100, 
    "Scar:\tI do not have time for you right now."));
    
    //std::unique_ptr<Item> i(new Breakable("cc", "cc", 1));
    //prideLands->addItem(std::move(i));

    prideLands->addAnimal(std::move(mufasa));
    scarsPlace->addAnimal(std::move(scar));
    Environment* start = prideLands.get();

    _map.push_back(std::move(prideLands));
    _map.push_back(std::move(scarsPlace));
    _map.push_back(std::move(waterHole));
    _map.push_back(std::move(elephantGraveyard));
    _map.push_back(std::move(djungle));
    _map.push_back(std::move(djungle2));
    _map.push_back(std::move(prideLands2));

    return start;
#endif
}

void storeMap(){
}

void needMoreParams(){
    std::cout << "Need another parameter" << std::endl;
}

void run(){
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
                    user->talk_to(reply[1]);
                else
                    std::cout << user->getSpeach() << std::endl;
                break;
            case Go :
                if(reply.size() > 1)
                    user->go(reply[1]);
                else
                    needMoreParams();
                break;
            case Look :
                if(reply.size() > 1)
                    user->look(reply[1]);
                else
                    user->look();
                break;
            case Exit :
                running = 0;
                break;
            case Cheeks:
                user->showInventory();
                break;
            case Fight :
                if(reply.size() > 1)
                    user->fight(reply[1]);
                else
                    needMoreParams();
                break;
            case Take :
                if(reply.size() > 1)
                    user->take(reply[1]);
                else
                    needMoreParams();
                break;
            case Use :
                if(reply.size() > 1)
                    user->use(reply[1]);
                else
                    needMoreParams();
                break;
            case Drop :
                if(reply.size() > 1)
                    user->drop(reply[1]);
                else
                    needMoreParams();
                break;
            case Help:
                printHelpMsg();
                break;
            default:
                std::cout << "Unknown command, write 'Help' for more information about what you can do" << std::endl;
                continue;
        }
        updateProgress(s_input);
    }
}

int main(){
#if DEBUG
    std::cout << "In debug mode" << std::endl;
#endif
    init();
    level = 0;
    Environment* startposition = loadMap();
    if(startposition == NULL) {
        std::cout << "Unable to open map, Exiting the game!" << std::endl; 
        return 1;
    }
    user = new User(startposition);
    run();
    storeMap();
    delete user;
    return 0;
}

void updateProgress(std::string input){
    switch(level){
        case 1:
            if(input == "Talk Mufasa"){
                _map[1]->getAnimal("Scar")->setSpeach("Simba:\tHey, Uncle Scar, guess what?\nScar:\tI despise guessing games.\nSimba:\tI'm gonna be King of Pride Rock.\nScar:\tOh, goody.\nSimba:\tMy dad just showed me the whole kingdom. And I'm gonna rule it all. Heheh.\nScar:\tYes. Well, forgive me for not leaping for joy. Bad back, you know.\nSimba:\tHey Uncle Scar, when I'm King, what'll that make you?\nScar:\tA monkey's uncle.\nSimba:\tYou're so weird.\nScar:\tYou have no idea.");
                ++level;
            }
            break;
    }
    
}

void init() {

}
