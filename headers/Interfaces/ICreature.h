#ifndef ICREATURE_H_
#define ICREATURE_H_

#include "healthBar.cc"
#include "IObject.h"
#include "IMap.h"

// global variables for maximum values of randomly generated stats
int MAX_DAMAGE = 20;
int MAX_STEALTH = 15;
int MAX_PERCEPTION = 18;
int MAX_SKILL = 15;

/**
 * @class ICreature
 * @brief represents various creatures that could be on the terrain
 * 
 * The IMap is the general interface for the different terrains that a player
 * might find themselves in. Has the basic functions that each terrain can do
 * like perceiving creatures in the terrain, checking and springing traps, and 
 * facilitating encounters between creatures
*/
class ICreature : public IObject{
    public:

      ICreature(){
         lives = 1;
         location = nullptr;
      }

     /**
      * @brief constructor for the most basic elements that are consistent across all entities
     */
     ICreature(IMap* start, int l){
        lives = l;
        location = start;
     }

     //virtual ~ICreature() {}
     
     /**
      * @brief resolves creature attempting to set a trap using randomly generated values
     */
     virtual void setTrap(){
        int damage = rand() % MAX_DAMAGE;
        int stealth = rand() % MAX_STEALTH;
        int skill = rand() % MAX_SKILL;

        ITrap* new_trap = new ITrap(damage, stealth, skill);
        location->addTrap(new_trap);
     }

     /**
      * @brief resolves perception check with random values
     */
     virtual void perceptionCheck(){
        currentPerception = rand() % MAX_PERCEPTION;
     }

    /**
     * @brief resolves setting stealth with random values
    */
     virtual void setStealth(){
        stealth = rand() % MAX_STEALTH;
     }

     /**
      * @brief gets creatures current perception roll value
      * 
      * @return returns current perception
     */
     virtual int getCurrentPerception(){ return currentPerception; }

     /**
      * @brief gets creatures current stealth roll value
      * 
      * @return returns stealth
     */
     virtual int getStealth(){ return stealth; }

     /**
      * @brief gets creatures passive perception
      * 
      * @return returns passive perception
     */
     virtual int getPassivePerception(){ return passivePerception; }

     virtual bool deathSequence(){
        lives -= 1;
        if(lives <= 0){
            delete this;
            return true;
        }
        return false;
     }

     /**
      * @brief generic check for anything with no modifiers
      * 
      * @return random value for check
     */
     virtual int check(){
        return rand() % 20;
     }

     /**
      * @brief gets the health bar
      * 
      * @return returns health bar
     */
     virtual healthBar* getHealthBar(){
        return health;
     }

     /**
      * @brief set all of the stats
     */
     virtual void setStats(){
        std::cout << "Please enter passive perception of character" << std::endl;
        std::cin >> passivePerception;

        std::cout << "Please enter stealth of character" << std::endl;
        std::cin >> stealth;

        int h;
        std::cout << "Please enter health of character" << std::endl;
        std::cin >> h;
        health = new healthBar(h);
     }
    
    /**
     * @brief Pure virtual because name depends on type of player
     * 
     * @return returns name
    */
     virtual std::string getName() = 0;

    protected:
     IMap* location;
     int passivePerception;
     int stealth;
     int currentPerception;
     healthBar* health;
     int lives;
     
};

#endif // ICREATURE_H_