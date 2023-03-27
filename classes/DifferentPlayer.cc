#ifndef DIFFERENT_PLAYER_H_
#define DIFFERENT_PLAYER_H_

#include "IEntity.h"
#include "IMap.h"

class DifferentPlayer : public IEntity {
    public:
     DifferentPlayer(IMap* start, int pp, int h, int l){
        passivePerception = pp;
        location = start;
        stealth = 10;
        lives = l;
        health = new healthBar(h);
        names = setName();
     }

     std::vector<std::string> setName(){
        std::vector<std::string> nameList = {};
        for(int i = 0; i < lives; i++){
            std::string n;
            std::cout << "Please enter the name of character " << i << std::endl;
            std::cin >> n;
            nameList.insert(nameList.begin(), n);
        }
     }

     int deathSequence(){
        lives -= 1;
        if(lives <= 0){
            delete this;
            return true;
        }
        names.pop_back();
        return false;
     }

    private:
     std::vector<std::string> names;
};

#endif // SAME_PLAYER_H