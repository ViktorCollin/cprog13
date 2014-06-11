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
#include "item/eatable.h"

using namespace the_lion_king_saga;

User* user;
std::vector<std::unique_ptr<Environment>> _map;
int level;
//Metod declarations (no header file) 
void updateProgress(std::string);
Environment* loadMap();

void needMoreParams(){
    std::cout << "Need another parameter" << std::endl;
}

void run(){
    char c_input[256];
    std::string s_input;
    int running = 1;
    while(running){
        if(user->isDead()) {
            std::cout << "You died, better luck next time" << std::endl;
            running = 0;
            break;
        }
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
                    user->printSpeach();
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
            case Eat :
                if(reply.size() > 1)
                    user->eat(reply[1]);
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
    level = 1;
    Environment* startposition = loadMap();
    if(startposition == NULL) {
        std::cout << "Unable to open map, Exiting the game!" << std::endl; 
        return 1;
    }
    user = new User(startposition);
    run();
    delete user;
    return 0;
}

void updateProgress(std::string input){
    switch(level){
        case 1:
            if(input == "Talk Mufasa"){
                _map[1]->getAnimal("Scar")->setSpeach("Simba:\tHey, Uncle Scar, guess what?\nScar:\tI despise guessing games.\nSimba:\tI'm gonna be King of Pride Rock.\nScar:\tOh, goody.\nSimba:\tMy dad just showed me the whole kingdom. And I'm gonna rule it all. Heheh.\nScar:\tYes. Well, forgive me for not leaping for joy. Bad back, you know.\nSimba:\tHey Uncle Scar, when I'm King, what'll that make you?\nScar:\tA monkey's uncle.\nSimba:\tYou're so weird.\nScar:\tYou have no idea. Did he tell you about the area where the sun don't reach?\nSimba:\tNo! He just said I was not allowed to go there\nScar:\tHe is absolutly right an Elephant graveyard is no place for a litele lion cub.");
                ++level;
            }
            break;
        case 2:
            if(input == "Talk Scar"){
                _map[2]->addNeighbor(_map[3].get(), North);
                ++level;
            }
            break;
        case 3:
            if(input == "Talk" && user->currentPosition()->name() == "The elephant graveyard"){
                std::cout << "Mufasa:\tRAARW!\nThe hyenas flee the seen\nMufasa:\tSimba, I'm very disappointed in you.\nSimba:\tI know.\nMufasa:\tYou could have been killed! You deliberately disobeyed me! And what's worse, you put Nala in danger!\nSimba:\tI was just trying to be brave like you.\nMufasa:\tSimba, I'm only brave when I have to be. Being brave doesn't mean you go looking for trouble.\nSimba:\tBut you're not scared of anything.\nMufasa:\tI was today.\nSimba:\tYou were?\nMufasa:\tYes. I thought I might lose you.\nSimba:\tWhoah. I guess even kings get scared, huh?\nMufasa:\tMmm-hmm.\nSimba:\tBut you know what?\nMufasa:\tWhat?\nSimba:\tI bet those hyenas were even scareder.\nMufasa:\tThat's 'cause nobody messes with your dad! Come here, you!" << std::endl;
                _map[3]->addNeighbor(_map[0].get(), South);
                _map[1]->getAnimal("Scar")->setSpeach("Scar:\tYou are a disgrace for our famely, leave the pride lands and never come back!");
                _map[0]->removeNeighbor(North);
                ++level;
            }
            break;
        case 4:
            if(input == "Talk Scar"){
                _map[0]->addNeighbor(_map[4].get(), South);
                ++level;
            }
            break;
        case 5:
        case 7:
            if(input == "Take Bugs"){
                ++level;
            }
            break;
        case 6:
            if(input == "Eat Bugs"){
                ++level;
            }else if(input == "Drop Bugs"){
                --level;
            }
            break;
        case 8:
            if(input == "Eat Bugs"){
                std::cout << "You have now grown into a magnificant lion" << std::endl;
                user->setSpeach("Simba:\tRAAAWR!");
                _map[4]->addNeighbor(_map[5].get(), East);
                ++level;
            }else if(input == "Drop Bugs"){
                --level;
            }
            break;
        case 9:
            if(input == "Talk Rafiki"){
                std::unique_ptr<Animal> mufasa(new Friend("Mufasa", 100,
                    "Mufasa's ghost:\t[apears among the stars] Simba, you have forgotten me.\nSimba:\tNo. How could I?\nMufasa's ghost:\tYou have forgotten who you are and so have forgotten me.\n\tLook inside yourself, Simba.\n\tYou are more than what you have become.\n\tYou must take your place in the Circle of Life."
                );
                _map[5]->addAnimal(std::move(mufasa));
                ++level;
            }
            break;
        case 10:
            if(input == "Talk Mufasa"){
                _map[5]->getAnimal("Rafiki")->setSpeach("Simba:\tI know what I have to do. But going back means I'll have to face my past.\n\tI've been running from it for so long.\n[Rafiki hits Simba on the head with his stick]\nSimba:\tOw! Jeez, what was that for?\nRafiki:\tIt doesn't matter. It's in the past.\nSimba:\tYeah, but it still hurts.\nRafiki:\tOh yes, the past can hurt. But from the way I see it,\n\tyou can either run from it, or... learn from it.\n[swings his stick again at Simba, who ducks out of the way]\nRafiki:\tHa. You see? So what are you going to do?\nSimba:\tFirst, I'm gonna take your stick.\n[Simba snatches Rafiki's stick and throws it and Rafiki runs to grab it]\nRafiki:\tNo, no, no, no, not the stick! Hey, where you going?\nSimba:\tI'm going back!\nRafiki:\tGood! Go on! Get out of here!");
                ++level;
            }
            break;
        case 11:
            if(input == "Talk Rafiki"){
                _map[5]->addNeighbor(_map[6].get(), South);
                ++level;
            }
            break;
    }
#ifdef DEBUG
    std::cout << "level: " << level << std::endl;
#endif

}

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
    std::unique_ptr<Environment> waterHole(new Day("The trail to the water hole", "You are on the your way to the water hole, but the plan is to reach the elephant graveyard. If you just could get rid of that stupid bird Zazu.", "lies the water hole"));
    std::unique_ptr<Environment> elephantGraveyard(new Night("The elephant graveyard", "you have arived at the scariest place in the world, the elephat graveyard. Ther is a lot of elephant skulls with large dark holes where the eyes used to be.", "lies the big dark elephant graveyard"));
    std::unique_ptr<Environment> djungle(new Djungle("Djungle", "The big lush djungle", "lies the djungle"));
    std::unique_ptr<Environment> djungle2(new Night("Djungle", "The night has fallen over the djungle", "lies the djungle"));
    std::unique_ptr<Environment> prideLands2(new Night("Pride lands", "This is what use to be your home", "lies the kingdom of the pride lands"));

    prideLands->addNeighbor(scarsPlace.get(), West);
    scarsPlace->addNeighbor(prideLands.get(), East);
    prideLands->addNeighbor(waterHole.get(), North);
    waterHole->addNeighbor(prideLands.get(), South);

    djungle->addNeighbor(djungle.get(), North);
    djungle->addNeighbor(djungle.get(), South);
    djungle->addNeighbor(djungle.get(), East);
    djungle->addNeighbor(djungle.get(), West);

    std::unique_ptr<Animal> mufasa(new Friend("Mufasa", 100, 
                "Mufasa:\tEverything you see exists together in a delicate balance.\n\tAs king, you need to understand that balance and respect all the creatures,\n\tfrom the crawling ant to the leaping antelope.\nSimba:\tBut, Dad, don't we eat the antelope?\nMufasa:\tYes, Simba, but let me explain.\n\tWhen we die, our bodies become the grass, and the antelope eat the grass.\n\tAnd so we are all connnected in the great Circle of Life.\n\tYou are NOT allowed to go to the areas the sun dont reach."));
    std::unique_ptr<Animal> scar(new Friend("Scar", 100, 
                "Scar:\tI do not have time for you right now."));

    std::unique_ptr<Animal> hygena1(new Enemy("Shanzi", 100, "Shanzi:\tMorr"));
    std::unique_ptr<Animal> hygena2(new Enemy("Banzai", 100, "Banzai:\tHehehe!")); 
    std::unique_ptr<Animal> hygena3(new Enemy("Ed", 100, "Ed:\tWho's this?"));

    std::unique_ptr<Animal> scar2(new Enemy("Scar", 100, "Scar:\tWhy did you come back?"));

    std::unique_ptr<Animal> timone(new Friend("Timone", 100, "Timoe:\tHi there, Friend!"));
    std::unique_ptr<Animal> pumba(new Friend("Pumba", 100, "Pumba:\tHakuna Matata"));

    elephantGraveyard->addAnimal(std::move(hygena1));
    elephantGraveyard->addAnimal(std::move(hygena2));
    elephantGraveyard->addAnimal(std::move(hygena3));

    prideLands2->addAnimal(std::move(scar2));
    
    
    std::unique_ptr<Animal> rafiki(new Friend("Rafiki", 100, 
        "Rafiki\tAsante sana Squash banana, Wiwi nugu Mi mi apana.\nSimba\tCome on, will you cut it out?\nRafiki\tCan't cut it out. It will grow right back. Hehehe.\nSimba\tCreepy little monkey. Would you stop following me! Who are you?\nRafiki\tThe question is, who... are you?\nSimba\t[sighs] I thought I knew, but now I'm not so sure.\nRafiki\tWell, I know who you are! Shh. Come here, it's a secret.\n[Whispers, then grows louder]\nRafiki\tAsante sana Squash banana, Wiwi nugu Mi mi apana!\nSimba\tEnough already! What's that supposed to mean, anyway?\nRafiki\tIt means you're a baboon... and I'm not.\nSimba\tI think you're a little confused.\nRafiki\tWrong! I'm not the one who's confused. You don't even know who you are!\nSimba\tOh, and I suppose you know?\nRafiki\tSure do. You're Mufasa's boy!\n[Simba turns around to look at him, shocked]\nRafiki\tBye!"));
    //std::unique_ptr<Item> i(new Breakable("cc", "cc", 1));
    //prideLands->addItem(std::move(i));
    djungle->addAnimal(std::move(timone));
    djungle->addAnimal(std::move(pumba));

    std::unique_ptr<Item> i(new Eatable("Bugs", "Bugs", 1));
    djungle->addItem(std::move(i));

    prideLands->addAnimal(std::move(mufasa));
    scarsPlace->addAnimal(std::move(scar));
    
    
    
    djungle2->addAnimal(std::move(rafiki));
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
