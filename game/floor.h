#ifndef __FLOOR__
#define __FLOOR__

#include <vector>
#include <string>
#include <memory>
#include "state.h"

class Game;
class Cell;
#include "chamber.h"
//class Chamber;
class Character;
class Treasure;
class Potion;
class Enemy;
class PC;
class Stair;
class Compass;
class BarrierSuit;
#include "subjects/characters/playable/PC.h"

class Info;

using namespace std;

struct InvalidFloorExn{
    string s = "Floor file is invalid, please re-run game";
};

class Floor {
private:

    Game &g; // game is observer

    const size_t gridWidth = 80;
    const size_t gridHeight = 25;
    const size_t infoRows = 5;
    const size_t numChamber = 5;

    const int numEnemies = 20;
    const int numPotions = 10;
    const int numTreasure = 10; // 10 piles of gold

    int floorNum; // which floor

    string terrainFile; // file to read floor from
    string floorFile; // file to read floor from

    vector< vector< Cell > > grid;
    vector<Chamber> chambers;

    vector<shared_ptr<Enemy>> enemies;
    vector<shared_ptr<Treasure>> treasures;
    vector<shared_ptr<Potion>> potions;

    shared_ptr<PC> player; // decorated player on this floor
    int playerLocX;
    int playerLocY;
    int playerChamber;

    shared_ptr<Stair> stair; // one stair each floor
    shared_ptr<Compass> compass; // one compass each floor
    shared_ptr<BarrierSuit> bSuite;

    void readTerrain();
    void floorFromFile(string filename);
    void makeChambers();

public:
    int getPlayerHP();
    int getPlayerAtk();
    int getPlayerDef();
    int getplayerX() {return playerLocX;}
    int getplayerY() {return playerLocY;}
    int getplayerChamber() {return playerChamber;}
    ~Floor() = default; // default constructor
    Floor(Game& g, int fnum); // random floor (read terrain from cc3kterrain.txt)
    Floor(Game& g, int fnum, string floorfile); // read from floor file
    void setPlayer(std::shared_ptr<PC> p);
    void moveEnemies();
    void move(Action a);
    void action(Action a, Action b);
    void updateArgs(string s);
    Info newXY(int currX, int currY, Action a);
};

#endif
