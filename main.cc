#include "ITrap.h"
#include "basicTrap.cc"
#include "healthBar.cc"
#include "SamePlayer.h"
#include "DifferentPlayer.h"

int main(int argc, char** argv) {
    // basic trap test
    ITrap* testTrap = new basicTrap(1, 2, 3);
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

    // player tests
    SamePlayer* player1 = new SamePlayer(3);

}

/*#include "ICreature.h"
#include "IMap.h"
#include "ITrap.h"
#include "startLoc.h"
#include "DifferentPlayer.h"
#include "SamePlayer.h"


int main(int argc, char** argv) {
    IMap* testMap = new startLoc();
    ICreature* player = new DifferentPlayer(testMap, 1);
    ITrap* trap = new ITrap(15, 15, 15);

    testMap->addTrap(trap);
    testMap->addCreature(player);
    testMap->stealthSet();
    std::cout << "Player stealth" << player->getStealth() << std::endl;

    auto percepCheck = testMap->perceptionCheck(10);
    if(percepCheck.size() > 0){
        std::cout << percepCheck[0] << std::endl;
    }
    
    player->perceptionCheck();
    std::cout << "Player perception" << player->getCurrentPerception() << std::endl;
    auto traps = testMap->trapCheck(player->getCurrentPerception());
    if(traps.size() > 0){
        std::cout << traps[0] << std::endl;
    }

    std::cout << "Trap sprung check" << std::endl;
    testMap->trapSprung(player, trap);
    std::cout << player->getHealthBar()->getCurrentHealth() << std::endl;

    ICreature* player2 = new SamePlayer(testMap, 1);
    testMap->encounter(player, player2);

    std::cout << "Player 2 dies" << std::endl;
    testMap->creatureDies(player2);

};*/