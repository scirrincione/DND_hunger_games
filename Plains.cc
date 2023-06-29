#ifndef PLAINS_H_
#define PLAINS_H_

#include "IMap.h"

class Plains : public IMap {
    public:
    Plains(){
        stealth = .6;
    }
};

#endif // PLAINS_H_