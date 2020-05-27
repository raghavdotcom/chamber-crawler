#ifndef __GAME__
#define __GAME__

#include <memory>
#include <string>
#include "model.h"

#include "floor.h"
class PC;

using namespace std;

class Game : public Model
{
private:
    std::vector<std::unique_ptr<Floor>> floors; // make 1 floor at a time
    shared_ptr<PC> gamePlayer;
    int currFloor = 1;
    std::string race;
    // may have barrier suite
public:
    std::string getRace() {return race;}
    void play();
    Game(bool curses, string loadfrom); // load game constructor
    shared_ptr<PC> getPlayer() {return gamePlayer;}
};

#endif
