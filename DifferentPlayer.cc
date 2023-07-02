#include "DifferentPlayer.h"



DifferentPlayer::DifferentPlayer(int l) : ICreature(l) {
        setStats();
        setNames();
     }

void DifferentPlayer::setNames(){
        for(int i = 0; i < lives; i++){
            std::string n;
            std::cout << "Please enter the name of character " << i+1 << std::endl;
            std::cin >> n;
            names.insert(names.begin(), n);
        }
     }

bool DifferentPlayer::deathSequence(){
        lives -= 1;
        if(lives <= 0){
            delete this;
            return true;
        }
        names.pop_back();
        setStats();
        return false;
   }

std::string DifferentPlayer::getName(){
        return names.front();
     }

void DifferentPlayer::perceptionCheck(){
        printf("Enter perception check\n");
        std::cin >> currentPerception;
}

void DifferentPlayer::stealthCheck(){
        printf("Enter stealth check\n");
        std::cin >> stealth;
}