#ifndef __WRITTEN___H__
#define __WRITTEN___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "../game/state.h"

class Game;

class Written: public View{
  std::ostream& out;
  std::string race;
  int gold;
  int floor;
  int hp;
  int atk;
  int def;
  std::string action;

  Game& game;
 public:
  Written(std::string race, int gold, int floor, int hp , int atk, int def,std::string action, Game& g);
  void update(const std::string& msg) override;
  void update(int row, int col, char disp) override;
  void updateView() override;
  void update(std::string race, int gold, int floor, int HP, int atk, int def, std::string action) override;
};
#endif
