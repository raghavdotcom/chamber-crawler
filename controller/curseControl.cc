#include "curseControl.h"
#include <string>

CurseKeyboard::CurseKeyboard() {
  mapping['w'] = Action::NO;
  mapping['d'] = Action::EA;
  mapping['s'] = Action::SO;
  mapping['a'] = Action::WE;
  mapping['q'] = Action::NW;
  mapping['e'] = Action::NE;
  mapping['z'] = Action::SW;
  mapping['c'] = Action::SE;
  mapping[' '] = Action::ATTACK;
  mapping['m'] = Action::USE;
  mapping[KEY_UP] = Action::NO;
  mapping[KEY_RIGHT] = Action::EA;
  mapping[KEY_DOWN] = Action::SO;
  mapping[KEY_LEFT] = Action::WE;
}

Action CurseKeyboard::action(){
  int n;
  while ( (n = getch()) == ERR ) continue;

  if ( mapping.find(n) != mapping.end() ){
    return mapping[n];
  }
  return Action::INVALID;
}
