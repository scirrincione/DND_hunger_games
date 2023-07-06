#include "SamePlayer.h"

SamePlayer::SamePlayer(int l) : ICreature(l){
        setStats();
        setName();
     }

SamePlayer::SamePlayer(int l, std::string n, int pp, int s, int h){
        lives = l;
        name = n;
        passivePerception = pp;
        stealth = s;
        health = new healthBar(h);
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

int SamePlayer::check(){
        int c;
        printf("Enter check: ");
        std::cin >> c;
        return c;
}