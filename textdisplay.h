#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"
#include "floor.h"
#include "subject.h"
class Cell;

class TextDisplay: public Observer<Info, State> {
  char theDisplay[30][79];
  //std::vector<std::vector<char>> theDisplay;
  const col = 79;
  const row = 30;
  // 5 row are reserved for diplaying information
  PC player;
  
  
 public:
  TextDisplay();

  //void set_char(const Colour &colour, int row, int col);
  void update(Subject<Info, State> &whoNotified) override;

  void defGrid();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

