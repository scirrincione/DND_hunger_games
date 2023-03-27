#ifndef MOUNTAIN_H_
#define MOUNTAIN_H_

#include "IMap.h"

class Mountain : public IMap {
    public:
    Mountain(){
        stealth = 1.1;
    }
};

#endif // MOUNTAIN_H_