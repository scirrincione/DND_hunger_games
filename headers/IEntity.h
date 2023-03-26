#ifndef IENTITY_H_
#define IENTITY_H_

#include <iostream>
#include <stdlib.h>
#include "healthBar.cc"

// global variables for maximum values of randomly generated stats
int MAX_DAMAGE = 20;
int MAX_STEALTH = 15;
int MAX_PERCEPTION = 18;
int MAX_SKILL = 15;

class IEntity {
    public:

     /**
      * @brief constructor for entities giving where they start and their passive perception starting
      *        with a basic check of 10 for stealth for if those around notice them
     */
     IEntity(IMap* start, int pp, int h, int l, std::string n){
        passivePerception = pp;
        location = start;
        stealth = 10;
        lives = l;
        health = new healthBar(h);
        name = n;
     }

     virtual ~IEntity(){}
     
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

     virtual int deathSequence(){
        lives -= 1;
        if(lives <= 0){
            delete this;
            return true;
        }
        return true;
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
     * @brief get name
     * 
     * @return returns name
    */
     virtual std::string getName(){
        return name;
     }

    private:
     IMap* location;
     int passivePerception;
     int stealth;
     int currentPerception;
     healthBar* health;
     int lives;
     std::string name;
     
};

#endif // IENTITY_H_