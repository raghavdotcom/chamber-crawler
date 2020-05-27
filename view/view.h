#ifndef ___VIEW___H__
#define ___VIEW___H__

#include <string>
#include "../game/state.h"

class View{
 public:
  virtual ~View() = default;
  virtual void update(const std::string& msg) = 0;
  virtual void update(int row, int col, char disp) = 0;
  virtual void updateView() = 0;
  virtual void update(std::string race, int gold, int floor, int HP, int atk, int def, std::string action) = 0;
};

#endif
