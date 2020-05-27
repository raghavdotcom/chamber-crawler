#ifndef __STANDARD___H__
#define __STANDARD___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "../game/state.h"

class Game;

class Standard: public View{
  std::vector<std::vector<char>> display;
  std::ostream& out;

  Game& game;
 public:
  Standard(Game& g);
  void update(const std::string& msg) override; // do nothing
  void update(int row, int col, char disp) override;
  void updateView() override;
  void update(std::string race, int gold, int floor, int HP, int atk, int def, std::string action) override; // do nothing
  ~Standard() {}
};
#endif
