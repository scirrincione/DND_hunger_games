#ifndef COMPOSITE_FACTORY_H
#define COMPOSITE_FACTORY_H

#include "IFactory.h"

class CompositeFactory : public IFactory {
    public: 
     IObject* CreateObject(std::string type);

     void AddFactory(IFactory* newFactory);

     virtual ~CompositeFactory();

     private:
      std::vector<IFactory*> factories;
};

#endif // COMPOSITE_FACTORY_H