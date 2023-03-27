#ifndef DIFFERENT_PLAYER_H_
#define DIFFERENT_PLAYER_H_

#include "ICreature.h"
#include "IMap.h"

class DifferentPlayer : public ICreature {
    public:
     
     ~DifferentPlayer(){}

     DifferentPlayer(IMap* start, int pp, int h, int l) : ICreature(start, l) {
        setStats();
        setNames();
     }

     void setNames(){
        for(int i = 0; i < lives; i++){
            std::string n;
            std::cout << "Please enter the name of character " << i+1 << std::endl;
            std::cin >> n;
            names.insert(names.begin(), n);
        }
     }

     bool deathSequence(){
        lives -= 1;
        if(lives <= 0){
            delete this;
            return true;
        }
        names.pop_back();
        setStats();
        return false;
     }

     std::string getName(){
        return names.front();
     }

    private:
     std::vector<std::string> names;
};

#endif // SAME_PLAYER_H