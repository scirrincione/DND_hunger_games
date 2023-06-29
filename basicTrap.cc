//#ifndef BASIC_TRAP_H
//#define BASIC_TRAP_H

#include "ITrap.h"

class basicTrap : public ITrap {
    public:
    
     basicTrap(int d, int s, int sk) : ITrap(d, s, sk){};

     int uniqueFunction(){
        return 0;
     }

    private:
};

//#endif // BASIC_TRAP_H