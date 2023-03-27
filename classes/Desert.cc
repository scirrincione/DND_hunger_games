#ifndef DESERT_H_
#define DESERT_H_

#include "IMap.h"

class Desert : public IMap {
    public:
    Desert(){
        stealth = .9;
    }
};

#endif // DESERT_H_