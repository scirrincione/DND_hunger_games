#ifndef I_FACTORY_H
#define I_FACTORY_H

#include "IObject.h"

class IFactory {
    public:
     virtual ~IFactory() {}

     virtual IObject* CreateObject(std::string type) = 0;
};

#endif // I_FACTORY_H