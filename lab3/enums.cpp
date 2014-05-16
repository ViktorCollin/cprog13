#ifndef ENUMS_H
#define ENUMS_H
namespace the_lion_king_saga {
	enum Action{
	    INVALID_ACTION,
		Go,
		Look,
		Exit,
		Fight,
		Take,
		Drop,
		Inventory
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
        {"Exit", Exit},
        {"Fight", Fight},
        {"Take", Take},
        {"Drop", Drop},
        {"Inventory", Inventory}
    };
    
    static const std::map<std::string, Direction> directionMap = {
        {"North", North},
        {"South", South},
        {"East", East},
        {"West", West}
    };
	
	static Direction strToDirection(std::string str){
        auto it = directionMap.find(str);
        if(it == directionMap.end()) return INVALID_DIRECTION;
        return it->second;
	}
	
	static Action strToAction(std::string str){
        auto it = actionMap.find(str);
        if(it == actionMap.end()) return INVALID_ACTION;
        return it->second;
	}
	
	static std::string listActions(){
        std::string ret;
        for(auto i : actionMap){
            ret.append(i.first);
        }
        return ret;
	}
	
	static std::string listDirections(){
        std::string ret;
        for(auto i : directionMap){
            ret.append(i.first);
        }
        return ret;
	}
}
#endif
