#ifndef ITRAP_H_
#define ITRAP_H_

class ITrap {
    public:
     
     /**
      * @brief sets up trap with damage it does and difficulty to find it
     */
     ITrap(int d, int s, int sk){
        damage = d;
        stealth = s;
        skill = sk;
     }

     virtual int getStealth() { return stealth; }

     virtual int getDamage() { return damage; }

     virtual int getSkill() { return skill; }

    private:
     int damage;
     int stealth;
     int skill;
};

#endif // ITRAP_H_