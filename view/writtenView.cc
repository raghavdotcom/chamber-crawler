#include "writtenView.h"
#include <iostream>
#include "../game/game.h"

Written::Written(std::string race, int gold, int floor, int hp , int atk, int def, std::string action, Game& g) :
out{std::cout}, race{race}, gold{gold}, hp{hp}, atk{atk}, def{def}, action{action}, game{g} {}

void Written::update(std::string race, int gold, int floor, int hp, int atk, int def, std::string action) {
  this->race = race;
  this->gold = gold;
  this->floor = floor;
  this->hp = hp;
  this->atk = atk;
  this->def = def;
  this->action  = action;
}

void Written::update(const std::string& msg) {
  this->action += msg;
}

void Written::update(int row, int col, char disp){}

void Written::updateView(){
  out << "Race: " << race << "  " << "Gold: " << gold << "                                        " << "Floor " << floor << std::endl;
  out << "HP: " << hp << std::endl;
  out << "Atk: " << atk << std::endl;
  out << "Def: " << def << std::endl;
  out << "Action: " << action << std::endl;
}
