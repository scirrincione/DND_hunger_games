#ifndef HEALTH_BAR
#define HEALTH_BAR

#include <iostream>
#include <stdlib.h>

//int MAX_HEALTH = 40; // default health value

class healthBar {
    public:

     /**
      * @brief default constructor if no health value is given, uses MAX_HEALTH
     */
     healthBar(){
        currentHealth = 40;
        maxHealth = 40;
     }

     /**
      * @brief constructor to set current and max health to given health value
     */
     healthBar(int h){
        currentHealth = h;
        maxHealth = h;
     }

     /**
      * @brief sets current health according to damage taken and returns true if dead
     */
     bool takeDamage(int damage){
        return (currentHealth -= damage) <= 0;
     }

     /**
      * @brief sets current health according to damage healed, can't heal over max
     */
     void healDamage(int damage){
        currentHealth = (currentHealth + damage) - (currentHealth % maxHealth);
     }

     /**
      * @brief gets current health
      * 
      * @return returns current health value
     */
     int getCurrentHealth(){
        return currentHealth;
     }
    
     /**
      * @brief gets max health
      * 
      * @return returns max health value
     */
     int getMaxHealth(){
        return maxHealth;
     }

     /**
      * @brief prints health bar for testing purposes
     */
    void printHealthBar(){
      printf("Current health: %i \n Max health: %i\n", currentHealth, maxHealth);
    }

    private:
     int currentHealth;
     int maxHealth;
};

#endif // HEALTH_BAR