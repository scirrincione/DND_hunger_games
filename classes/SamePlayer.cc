#ifndef SAME_PLAYER_H_
#define SAME_PLAYER_H_

#include "IEntity.h"
#include "IMap.h"

class SamePlayer : public IEntity {
    public:
     SamePlayer(IMap* start, int pp, int h, int l, std::string n){
        passivePerception = pp;
        location = start;
        stealth = 10;
        lives = l;
        health = new healthBar(h);
        name = n;
     }

    private:
     std::string name;
};

#endif // SAME_PLAYER_H