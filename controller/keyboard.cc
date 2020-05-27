#include "keyboard.h"
#include <string>

Keyboard::Keyboard(std::istream&in): in{in} {
  theMap["no"] = Action::NO;
  theMap["ea"] = Action::EA;
  theMap["so"] = Action::SO;
  theMap["we"] = Action::WE;
  theMap["nw"] = Action::NW;
  theMap["ne"] = Action::NE;
  theMap["sw"] = Action::SW;
  theMap["sw"] = Action::SE;
  theMap["u"] = Action::USE;
  theMap["a"] = Action::ATTACK;
}

Action Keyboard::action(){
  std::string buffer;
  in >> buffer;
  if ( in ){
    if ( buffer == "remap" ){
      std::string oldCmd, newCmd;
      in >> oldCmd >> newCmd;
      return Action::NONE;
    } else {
      return theMap[buffer];
    }
  }
  return Action::INVALID;
}
