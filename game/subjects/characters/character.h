#ifndef __CHARACTER__
#define __CHARACTER__
#include "../subject.h"
#include "../items/item.h"

#include <memory>

class PC;

using namespace std;

class Character : public Subject {

protected:
    int maxHP;
    int defaultAtk;
    int defaultDef;
    int HP;
    int atk;
    int def;
public:
    Character(int hp, int atk, int def, int x, int y, char c) 
    : maxHP{hp}, defaultAtk{atk}, defaultDef{def}, HP{hp}, atk{atk}, def{def}, Subject{x,y,c} {}
   // virtual void move() = 0;
    virtual int attack(std::shared_ptr<Character>) = 0;
    virtual int attackBy(int) = 0;
    //virtual void use(std::shared_ptr<PC>) = 0;
    void addGold(int val);
    int getGold();
    int getHP() {return HP;}
    int getAtk() {return atk;}
    int getDef() {return def;}
    int getMHP() {return maxHP;}
    int getDAtk() {return defaultAtk;}
    int getDDef() {return defaultDef;}
    void setAtk(int n) {atk = n;}
    void setDef(int n) {def = n;}
    void setHP(int n) { if (n <= maxHP) HP = n;}
    void setDAtk(int n) {defaultDef = n;}
    void setDdef(int n) {defaultAtk = n;}
    void resetBuffs() {
        atk = defaultAtk;
        def = defaultDef;
    }
    virtual ~Character() = default;
};

#endif
