#ifndef ENUMS_H
#define ENUMS_H
namespace the_lion_king_saga {
	enum Actions{
		Go,
		Look,
		Exit,
		Fight,
		Take,
		Drop,
		Inventory
	};

	enum Direction{
	    MISSING,
		North,
		South,
		East,
		West
	};
	
	static Direction strToDirection(std::string str){
        if(str == "North") return North;
        if(str == "South") return South;
        if(str == "East") return East;
        if(str == "West") return West;
        return MISSING;
	}
}
#endif
