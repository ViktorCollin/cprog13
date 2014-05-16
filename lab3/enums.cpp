#ifndef ENUMS_H
#define ENUMS_H
#include <iostream>
namespace the_lion_king_saga {
	enum Action{
	    INVALID_ACTION,
		Go,
		Look,
		Exit,
		Fight,
		Take,
		Drop,
		Cheeks,
		Help,
	};

	enum Direction{
	    INVALID_DIRECTION,
		North,
		South,
		East,
		West
	};
	
    static const std::map<std::string, Action> actionMap = {
        {"Go", Go}, 
        {"Look", Look}, 
        {"Fight", Fight},
        {"Take", Take},
        {"Drop", Drop},
        {"Cheeks", Cheeks},
        {"Help", Help},
        {"Exit", Exit}
    };
    
    static const std::map<std::string, Direction> directionMap = {
        {"North", North},
        {"South", South},
        {"East", East},
        {"West", West}
    };

    static Action strToAction(std::string str){
        auto it = actionMap.find(str);
        if(it == actionMap.end()) return INVALID_ACTION;
        return it->second;
	}

	static Direction strToDirection(std::string str){
        auto it = directionMap.find(str);
        if(it == directionMap.end()) return INVALID_DIRECTION;
        return it->second;
	}

	static std::string actionToStr(Action a){
        for(auto i : actionMap){
            if(i.second == a) return i.first;
        }
        return "Invalid action!";
	}
	
	static std::string directionToStr(Direction dir){
        for(auto i : directionMap){
            if(i.second == dir) return i.first;
        }
        return "Invalid direction!";
	}

	static std::string listActions(){
        std::string ret;
        for(auto i : actionMap){
            ret.append(", ");
            ret.append(i.first);
        }
        return ret.substr(2);
	}
	
	static std::string listDirections(){
        std::string ret;
        for(auto i : directionMap){
            ret.append(", ");
            ret.append(i.first);
        }
        return ret.substr(2);
	}
	
	static void printHelpMsg(){
	    std::cout << 
	    "Here is a list of avalible actions you could do\n" <<
	    "<> marks mandatory parameter\n" <<
	    "[] marks optional parameter\n" <<
	    "\n" <<
	    "Avalible commands are:\n" <<
	    "Go:\t\'Go <Direction>\'\t- Is used to move between different environments.\n" <<
	    "Look:\t\'Look [Direction]\'\t- Is used to look around the current environment, \n" <<
	        "\t\t\t\t  to take a closer look use the directions parameter.\n" <<
	    "Fight:\t\'Fight <Character>\'\t- Is used to attack and character in the environment.\n" <<
	    "Take:\t\'Take <Item>\'\t\t- Is used to pick up an item in your mouth if it is not full.\n" <<
	    "Drop:\t\'Drop <Item>\'\t\t- Is used to drop an item from your mouth to make room for more.\n" <<
	    "Cheeks:\t\'Cheeks\'\t\t- Lists all items you are currently holding in your cheeks pouches.\n"<<
	    "Help:\t\'Help\'\t\t\t- Prints this message.\n" <<
	    "Exit:\t\'Exit\'\t\t\t- Quits the game without saving." << std::endl;
	}
}
#endif
