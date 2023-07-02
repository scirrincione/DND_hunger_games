#include "SamePlayer.h"

SamePlayer::SamePlayer(int l) : ICreature(l){
        setStats();
        setName();
     }

void SamePlayer::setName(){
        std::cout << "Please enter the name of the character" << std::endl;
        std::cin >> name;
     }

std::string SamePlayer::getName(){
        return name;
     }

void SamePlayer::perceptionCheck(){
        printf("Enter perception check\n");
        std::cin >> currentPerception;
}

void SamePlayer::stealthCheck(){
        printf("Enter stealth check\n");
        std::cin >> stealth;
}