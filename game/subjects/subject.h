#ifndef __SUBJECT_HH__
#define __SUBJECT_HH__
#include <vector>
#include "observer.h"
#include "../state.h"

/* A note on InfoType and StateType:

   We have separated the collection of fields into two parts:  its Info
   and its State.

   Info is for the parts of the subject inherent to what it is:  its position
   and its colour.

   State is for the parts of the subject that, when changed, trigger
   notifications.  This is the information that the Observer "gets" when it
   calls getState on the subject.  It comprises the type of state, a direction,
   and a colour.  For more details, see state.h.
*/

// DO NOT MODIFY THIS FILE!

// template <typename InfoType, typename StateType> class Observer;

// template <typename InfoType, typename StateType> class Subject {
//   std::vector<Observer<InfoType, StateType>*> observers;
//   StateType state;
//  protected:
//   void setState(StateType newS);
//  public:
//   void attach(Observer<InfoType, StateType> *o);
//   void notifyObservers();
//   virtual InfoType getInfo() const = 0;
//   StateType getState() const;
// };

// template <typename InfoType, typename StateType>
// void Subject<InfoType, StateType>::attach(Observer<InfoType, StateType> *o) {
//   observers.emplace_back(o);
// }

// template <typename InfoType, typename StateType>
// void Subject<InfoType, StateType>::notifyObservers() {
//   for (auto &ob : observers) ob->notify(*this);
// }

// template <typename InfoType, typename StateType>
// void Subject<InfoType, StateType>::setState(StateType newS) { state = newS; }

// template <typename InfoType, typename StateType>
// StateType Subject<InfoType, StateType>::getState() const { return state; }

class Observer;

class Subject
{
protected:
  Info info;
  std::vector<Observer*> observers;
  void setSymbol(char c) {info.symbol = c;}
  /* data */
public:
  void setPos(int x, int y) {
  info.x = x;
  info.y = y;
  }
  Info getInfo() {return info;}
  Subject(char symbol) : info{Info{0,0,symbol}} {}
  Subject(int x, int y, char symbol) : info{Info{x,y,symbol}} {}
  virtual ~Subject() = default;
  void attach(Observer *o);
  void notifyObservers();
  // virtual void use(Character*) {}
  //   virtual int attack(Character*);
  //   virtual int attackBy(int);
  //   virtual void addGold(int val);
  //   virtual int getGold();
  //   virtual int getHP();
  //   virtual int getAtk();
  //   virtual int getDef();
  //   virtual int getMHP();
  //   virtual int getDAtk() ;
  //   virtual int getDDef() ;
  //   virtual void setAtk(int n) ;
  //   virtual void setDef(int n) ;
  //   virtual void setHP(int n) ;
  //   virtual void setDAtk(int n);
  //   virtual void setDdef(int n);
  //   virtual void resetBuffs() ;
};

// void Subject::attach(Observer *o){
//   observers.emplace_back(o);
// }
// void Subject::notifyObservers(){
//   for (auto &ob : observers) ob->notify();
// }

#endif
