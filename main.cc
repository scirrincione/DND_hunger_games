#include "ITrap.h"
#include "basicTrap.cc"
#include "healthBar.cc"
#include "SamePlayer.h"
#include "DifferentPlayer.h"
#include "startLoc.h"

int main(int argc, char** argv) {
    // basic trap test
    ITrap* testTrap = new basicTrap(20, 2, 3);
    testTrap->printTrap();

    // health bar test unique value
    healthBar* testHealth = new healthBar(30);
    printf("Before changes\nCurrent health: %i\nMax health: %i\n", testHealth->getCurrentHealth(), testHealth->getMaxHealth());
    testHealth->takeDamage(20);
    printf("After taking 20 damage\nCurrent health: %i\nMax health: %i\n", testHealth->getCurrentHealth(), testHealth->getMaxHealth());

    // health bar test preset value
    healthBar* testHealth1 = new healthBar();
    printf("Before changes\n");
    testHealth1->printHealthBar();
    testHealth1->takeDamage(20);
    printf("After taking 20 damage\n");
    testHealth1->printHealthBar();
    testHealth1->healDamage(10);
    printf("After healing 10 damage\n");

    // same player tests
    ICreature* player1 = new SamePlayer(3, "test1", 3, 4, 30);/*
    printf("Creating trap from player 1\n");
    ITrap* trap1 = player1->createTrap();
    trap1->printTrap();
    printf("Perception check\n");
    player1->perceptionCheck();
    printf("%i\n", player1->getCurrentPerception());
    printf("Stealth check\n");
    player1->stealthCheck();
    printf("%i\n", player1->getStealth());
    printf("Passive perception: %i\n", player1->getPassivePerception());
    printf("Death sequence\n");
    player1->takeDamage(40);
    printf("Lives: %i\n", player1->getLives());*/

    // different player tests
    ICreature* player2 = new DifferentPlayer(3, "test2", 1, 2, 20);
    /*printf("Creating trap from player 2\n");
    ITrap* trap2 = player2->createTrap();
    trap2->printTrap();
    printf("Perception check\n");
    player2->perceptionCheck();
    printf("%i", player2->getCurrentPerception());
    printf("Stealth check\n");
    player2->stealthCheck();
    printf("%i\n", player2->getStealth());
    printf("Passive perception: %i\n", player2->getPassivePerception());
    printf("Death sequence\n");
    player2->takeDamage(40);
    printf("Lives: %i\n", player2->getLives());*/

    // starting location tests
    IMap* starting = new startLoc();
    starting->addCreature(player1);
    starting->addCreature(player2);
    starting->addTrap(testTrap);
    std::vector<ICreature*> creatures = starting->perceptionCheck(5);
    for(ICreature* creature:creatures){
        std::cout << "Creatures seen: " << creature->getName() << "\n";
    }
    printf("Check 2");
    starting->stealthSet();
    creatures = starting->perceptionCheck(5);
    for(ICreature* creature:creatures){
        std::cout << "Creatures seen: " << creature->getName() << "\n";
    }
    
    std::vector<ITrap*> traps = starting->trapCheck(20);
    printf("Num traps: %li\n", traps.size());
    starting->trapSprung(player1, testTrap);
    printf("Player life after trap:\n" );
    player1->getHealthBar()->printHealthBar();
    starting->encounter(player1, player2);

};