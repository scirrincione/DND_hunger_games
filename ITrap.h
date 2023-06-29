#ifndef ITRAP_H_
#define ITRAP_H_

#include "IObject.h"

class ITrap : public IObject {
    public:
     
     /**
      * @brief sets up trap with damage it does and difficulty to find it
     */
     ITrap(int d, int s, int sk){
        damage = d;
        stealth = s;
        skill = sk;
     }

     /**
      * @return returns difficulty to find trap
     */
     virtual int getStealth() { return stealth; }

     /**
      * @return returns damage done by trap
     */
     virtual int getDamage() { return damage; }

     /**
      * @brief The skill of the trap is how well the trap is made and determines the 
      *        check needed to avoid it
      * 
      * @return returns skill of trap
     */
     virtual int getSkill() { return skill; }

     /**
      * @brief prints trap for testing purposes
     */
     virtual void printTrap() {
       printf("damage: %i skill: %i stealth: %i\n", damage, skill, stealth);
     }

    private:
     int damage;
     int stealth;
     int skill;
};

#endif // ITRAP_H_