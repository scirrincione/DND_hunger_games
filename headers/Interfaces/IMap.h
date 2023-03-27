#ifndef IMAP_H_
#define IMAP_H_

#include "ICreature.h"
#include "ITrap.h"
#include "IObject.h"

/**
 * @class IMap
 * @brief represents terrain for biomes
 * 
 * The IMap is the general interface for the different terrains that a player
 * might find themselves in. Has the basic functions that each terrain can do
 * like perceiving creatures in the terrain, checking and springing traps, and 
 * facilitating encounters between creatures
*/
class IMap : public IObject{
    public: 

     /**
      * @brief Basic constructor that assigns value of 1 for stealth - no effect
     */
    IMap() {
        stealth = 1;
    }

    virtual ~IMap() {}

    /**
     * @brief adds a trap to the map
    */
    virtual void addTrap(ITrap* trap) { traps.push_back(trap); }

    /**
     * @brief Check for if entities are seen given a check
     * 
     * @return returns a list of entities with stealth equal to or lower than check
    */
    virtual std::vector<ICreature*> perceptionCheck(int check) {
        std::vector<ICreature*> seenCreatures = {};
        for(auto creature : creatures){
            if(creature->getStealth()*stealth <= check){
                seenCreatures.push_back(creature);
            }
        }
        return seenCreatures;
    }

    /**
     * @brief Setting stealth for creatures in the area
    */
    virtual void stealthSet() {
        for(auto creature : creatures){
            creature->setStealth();
        }
    }

    /**
     * @brief Check if traps are seen given a check
     * @return returns list of traps with stealth equal to or lower than check
    */
    virtual std::vector<ITrap*> trapCheck(int check) {
        std::vector<ITrap*> seenTraps = {};
        for(auto trap : traps){
            if(trap->getStealth()*stealth <= check){
                seenTraps.push_back(trap);
            }
        }
        return seenTraps;
    }

    /**
     * @brief resolves trap being sprung on victim
    */
    virtual void trapSprung(ICreature* victim, ITrap* trap) {
        if(victim->check() < trap->getSkill()){
            if(victim->getHealthBar()->takeDamage(trap->getDamage())){ // if damage killed creature
                creatureDies(victim);
            }
        }
    }

    /**
     * @brief resolves if two beings encounter eachother
    */
    virtual void encounter(ICreature* firstCreature, ICreature* secondCreature) {
        std::cout << firstCreature->getName() << " encounters " << secondCreature->getName();
    }

    /**
     * @brief resolves character dying
    */
    virtual void creatureDies(ICreature* victim){
        for(int i = 0; i < creatures.size(); i++){
            if(creatures.at(i) == victim){
                if(creatures.at(i)->deathSequence()){ // if creature is dead
                    creatures.at(i) = nullptr;
                }
            }
        }
    }

    protected:
     float stealth; // variable that impacts creatures ability to hide in certain terrain
     std::vector<ICreature*> creatures; // creatures in biome
     std::vector<ITrap*> traps; // traps in biome
};

#endif // IMAP_H_