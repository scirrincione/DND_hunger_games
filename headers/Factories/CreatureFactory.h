#ifndef CREATURE_FACTORY_H_
#define CREATURE_FACTORY_H_

#include "IFactory.h"
#include "ICreature.h"

class CreatureFactory : public IFactory {
    public:
     
     virtual ~CreatureFactory(){}

     IObject* CreateObject(std::string type);
};

#endif // MAP_FACTORY_H