#ifndef SAME_PLAYER_H_
#define SAME_PLAYER_H_

#include "ICreature.h"
#include "IMap.h"

class SamePlayer : public ICreature {
    public:
     SamePlayer(int l);
     
     SamePlayer(int l, std::string n, int pp, int s, int h);

     void setName();

     std::string getName();

     void perceptionCheck();

     void stealthCheck();

     int check();

    private:
     std::string name;
};

#endif // SAME_PLAYER_H