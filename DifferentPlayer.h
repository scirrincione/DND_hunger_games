#ifndef DIFFERENT_PLAYER_H_
#define DIFFERENT_PLAYER_H_

#include "ICreature.h"
#include "IMap.h"

class DifferentPlayer : public ICreature {
    public:
     
     ~DifferentPlayer(){}

     DifferentPlayer(int l);

     void setNames();

     bool deathSequence();

     std::string getName();

     void perceptionCheck();

     void stealthCheck();

    private:
     std::vector<std::string> names;
};

#endif // SAME_PLAYER_H