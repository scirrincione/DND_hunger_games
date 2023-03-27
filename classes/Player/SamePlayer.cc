#ifndef SAME_PLAYER_H_
#define SAME_PLAYER_H_

#include "ICreature.h"
#include "IMap.h"

class SamePlayer : public ICreature {
    public:
     SamePlayer(IMap* start, int l) : ICreature(start, l){
        setStats();
        setName();
     }

     void setName(){
        std::cout << "Please enter the name of the character" << std::endl;
        std::cin >> name;
     }

    private:
     std::string name;
};

#endif // SAME_PLAYER_H