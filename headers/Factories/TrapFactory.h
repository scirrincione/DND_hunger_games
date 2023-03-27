#ifndef TRAP_FACTORY_H_
#define TRAP_FACTORY_H_

#include "IFactory.h"
#include "ITrap.h"

class TrapFactory : public IFactory {
    public:
     
     virtual ~TrapFactory(){}

     IObject* CreateObject(std::string type);
};

#endif // TRAP_FACTORY_H