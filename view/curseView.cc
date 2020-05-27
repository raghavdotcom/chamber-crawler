#include "curseView.h"
#include <ncurses.h>

Curses::Curses(std::string race, int gold, int floor, int hp , int atk, int def, std::string action,Game& g) :
race{race}, gold{gold},floor{floor}, hp{hp}, atk{atk}, def{def}, action{action}, game{g} {
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  // fill in map
  for (int i = 0; i < 25+1; i++ ){
    for( int j = 0; j < 79+1; j++ ){
      mvwaddch(stdscr, i+1, j+1, ' ');
    }
  }
}

void Curses::updateView(){
  refresh();
}

void Curses::update(const std::string& msg){
  // wmove(stdscr, height+3,0);
  // waddstr(stdscr,"                                              ");
  // wmove(stdscr, height+3,0);
  waddstr(stdscr,msg.c_str());
}

void Curses::update(int row, int col, char disp){
  mvwaddch(stdscr,row+1,col+1,disp);
}

#include <sstream>
using namespace std;

void Curses::update(std::string race, int gold, int floor, int HP, int atk, int def, std::string action) {
  // ostringstream oss1;
  // oss1 << "Race: " << race << "  " << "Gold: " << gold << "setw(50) << setfill(' ')" << "Floor " << floor << std::endl;
  // waddstr(stdscr,oss1.c_str());
  // ostringstream oss2;
  // oss2 << "HP: " << hp << std::endl;
  // waddstr(stdscr,oss2.c_str());
  // ostringstream oss3;
  // oss3 << "Atk: " << atk << std::endl;
  // waddstr(stdscr,oss3.c_str());
  // ostringstream oss4;
  // oss4 << "Def: " << def << std::endl;
  // waddstr(stdscr,oss4.c_str());
  // ostringstream oss5;
  // oss5 << "Action: " << action << std::endl;
  // waddstr(stdscr,oss5.c_str());
}

Curses::~Curses(){ endwin(); }
