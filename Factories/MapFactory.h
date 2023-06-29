#ifndef MAP_FACTORY_H_
#define MAP_FACTORY_H_

#include "IFactory.h"
#include "IMap.h"

class MapFactory : public IFactory {
    public:
     
     virtual ~MapFactory(){}

     IObject* CreateObject(std::string type);
};

#endif // MAP_FACTORY_H