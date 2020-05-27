#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "./game/game.h"

class Game;

using namespace std;

int main(int argc, char* argv[]){
  bool curses = false;
  string loadfrom = "";
  for ( int i = 1; i < argc; ++i ){
    std::string arg = argv[i];
    cout << arg << endl;
    if ( arg == "curses" ) curses = true;
    if ( arg == "--seed" ){
      ++i;
      size_t val;
      istringstream iss{argv[i]};
      if ( iss  >> val ){
        (val == 0) ? srand(time(NULL)) : srand(val); //  0 mean random
      } else {
        cerr << "Invalid seed" << endl;
        return 1;
      }
    } 
    if ( arg == "--read" ){
      ++i;
      std::string loadfile;
      istringstream iss{argv[i]};
      if ( iss  >> loadfile )
        loadfrom = loadfile;
      else {
        cerr << "Invalid load file" << endl;
        return 1;
      }
    }
  }
  Game game{curses, loadfrom};
  game.play();
}
