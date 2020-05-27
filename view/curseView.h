#ifndef __CURSES_VIEW___H__
#define __CURSES_VIEW___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "../game/state.h"

class Game;

class Curses: public View{

  std::string race;
  int gold;
  int floor;
  int hp;
  int atk;
  int def;
  std::string action;

  Game& game;
  std::map<State, char> displayMap;
 public:
  Curses(std::string race, int gold, int floor, int hp , int atk, int def, std::string action, Game& g);
  ~Curses();
  void update(const std::string& msg) override;
  void update(int row, int col, char disp) override;
  void updateView() override;
  void update(std::string race, int gold, int floor, int HP, int atk, int def, std::string action) override;
};
#endif
