#ifndef ___CONTROLLER___H__
#define ___CONTROLLER___H__

#include "../game/state.h"
#include <string>

class Controller{
  virtual Action action() = 0;
 public:
  Action getAction();
  virtual ~Controller() = default;
};
#endif
