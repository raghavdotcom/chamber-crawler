#include <fstream>
#include <iostream>
#include <memory>
#include <map>

#include "cell.h"
#include "floor.h"


#include "subjects/characters/character.h"
#include "subjects/characters/enemies/enemy.h"
#include "subjects/characters/enemies/merchant.h"
#include "subjects/characters/enemies/dragon.h"
#include "subjects/characters/enemies/phoenix.h"
#include "subjects/characters/enemies/troll.h"
#include "subjects/characters/enemies/werewolf.h"

#include "subjects/factory/enemyFactory.h"
#include "subjects/factory/potionFactory.h"
#include "subjects/factory/treasureFactory.h"

#include "subjects/items/item.h"
#include "subjects/items/potions/potion.h"
#include "subjects/items/treasures/treasure.h"
#include "subjects/items/guardedItems/guardedItem.h"
#include "subjects/items/stair.h"
#include "subjects/items/compass.h"
#include "subjects/items/barrierSuit.h"

#include "subjects/subject.h"

class Game;

using namespace std;

Floor::Floor(Game& g, int floor, string floorfile) : g{g}, floorNum{floor} {
    
    // initializing 2d vecotr of cells
    for (size_t c = 0; c < gridWidth; c++) {
        vector<Cell> cellCol;
        for (size_t r = 0; r < gridHeight; r++) {
            cellCol.emplace_back(Cell(c, r));
        }
        grid.emplace_back(cellCol);
    }

    // initializing Chambers
    for (size_t c = 0; c < numChamber; c++) {
        chambers.emplace_back(Chamber());
    }

    // read terrain from file
//    try{
    readTerrain();
    // } catch (InvalidFloorExn &instance) {
    //     cout << instance.s << endl;
    // }
    // make chambers
    makeChambers();
    floorFromFile(floorfile);
}

Floor::Floor(Game& g, int floor) : g{g}, floorNum{floor} { // random floor

    // initializing 2d vecotr of cells
    for (size_t c = 0; c < gridWidth; c++) {
        vector<Cell> cellCol;
        for (size_t r = 0; r < gridHeight; r++) {
            cellCol.emplace_back(Cell(c, r));
        }
        grid.emplace_back(cellCol);
    }

    // initializing Chambers
    for (size_t c = 0; c < numChamber; c++) {
        chambers.emplace_back(Chamber());
    }

    // read terrain from file
//    try{
    readTerrain();
    // } catch (InvalidFloorExn &instance) {
    //     cout << instance.s << endl;
    // }

    // make chambers
    makeChambers();

    // reserve spot for player
    playerChamber = rand() % numChamber; // numchmaber = 5
    size_t posChoose = rand() % chambers[playerChamber].getCells(); // number of cells in that chamber
    playerLocX = chambers[playerChamber][posChoose]->posX;
    playerLocY = chambers[playerChamber][posChoose]->posY;
    // not at this point grid[x][y].contents = player;
    grid[playerLocX][playerLocY].state = State::PLAYER;


    g.updateViews(playerLocX, playerLocY, '@');

    int chamberChoose;
    int x;
    int y;

    // choose Stairs
    chamberChoose = rand() % numChamber; // numchamber = 5
    while(chamberChoose == playerChamber) {
        chamberChoose = rand() % numChamber;
    }
    posChoose = rand() % chambers[chamberChoose].getCells(); // number of cells in that chamber
    x = chambers[chamberChoose][posChoose]->posX;
    y = chambers[chamberChoose][posChoose]->posY;
    grid[x][y].contents = make_shared<Stair>(x,y);
    grid[x][y].state = State::ITEM;
    g.updateViews(x, y, grid[x][y].contents->getInfo().symbol);

    // spawning potions
    int potionsToSpawn = numPotions;
    while (potionsToSpawn > 0) {
        chamberChoose = rand() % numChamber; // numchmaber = 5
        posChoose = rand() % chambers[chamberChoose].getCells(); // number of cells in that chamber
        x = chambers[chamberChoose][posChoose]->posX;
        y = chambers[chamberChoose][posChoose]->posY;
        if (grid[x][y].state == State::EMPTY) {
            potions.emplace_back(PotionFactory::generate(x, y));
            grid[x][y].contents = potions.back();
            grid[x][y].state = State::ITEM;
            g.updateViews(x, y, grid[x][y].contents->getInfo().symbol);
            potionsToSpawn -= 1;
        }
    }
    // choose gold
    int treasuresToSpawn = numTreasure;
    while (treasuresToSpawn > 0) {
        chamberChoose = rand() % numChamber; // numchmaber = 5
        posChoose = rand() % chambers[chamberChoose].getCells(); // number of cells in that chamber
        x = chambers[chamberChoose][posChoose]->posX;
        y = chambers[chamberChoose][posChoose]->posY;
        if (grid[x][y].state == State::EMPTY) {
            treasures.emplace_back(TreasureFactory::generate(x, y));
            grid[x][y].contents = treasures.back();
            grid[x][y].state = State::ITEM;
            g.updateViews(x, y, grid[x][y].contents->getInfo().symbol);
            treasuresToSpawn -= 1;
        }
    }
cout << "gold spots done works fine\n";
    // choose enemies
    int enemiesToSpawn = numEnemies;
    while (enemiesToSpawn > 0) {
        chamberChoose = rand() % numChamber; // numchmaber = 5
        posChoose = rand() % chambers[chamberChoose].getCells(); // number of cells in that chamber
        x = chambers[chamberChoose][posChoose]->posX;
        y = chambers[chamberChoose][posChoose]->posY;
        if (grid[x][y].state == State::EMPTY) {
            enemies.emplace_back(EnemyFactory::generate(x, y));
            grid[x][y].contents = enemies.back();
            grid[x][y].state = State::ENEMY;
            g.updateViews(x, y, grid[x][y].contents->getInfo().symbol);
            enemiesToSpawn -= 1;
        }
    }
    cout << "enemied done works fine\n";
}
// random floor contructor END

void Floor::setPlayer(std::shared_ptr<PC> p) {
    //grid[playerLocX][playerLocY].contents.reset();
    //grid[playerLocX][playerLocY].contents = dynamic_pointer_cast<Subject>(p);
    //player = p;
    //dynamic_pointer_cast<PC>(this->player) = dynamic_pointer_cast<PC>(p);
}

void Floor::moveEnemies() {
    vector<Cell*> leftToRightEnemies;
    for (int row = 0; row < gridHeight; row++) {
        for (int col = 0; col < gridWidth; col++) {
            if (grid[row][col].state == State::ENEMY) {
                leftToRightEnemies.emplace_back(&grid[row][col]);
            }
        }
    }
    cout <<"here";
    // iterate through all the enemies and move them in randomly order
    for(auto enemyCell : leftToRightEnemies) {
        while(true) {
            int direc = rand() % 8;
            int newX;
            int newY;
            int currX = enemyCell->posX;
            int currY = enemyCell->posY;
            // mapping numbers in clockwise direction 0-7 N - NW
            map<int , Action> actionMap;
            actionMap[0] = Action::NO;
            actionMap[1] = Action::NE;
            actionMap[2] = Action::EA;
            actionMap[3] = Action::SE;
            actionMap[4] = Action::SO;
            actionMap[5] = Action::SW;
            actionMap[6] = Action::WE;
            actionMap[7] = Action::NW;

            Action dire = actionMap[direc];
            newX = newXY(currX, currY, dire).x;
            newY = newXY(currX, currY, dire).y;

            if ((grid[newX][newY].terrain == Terrain::DOT) &&
                (grid[newX][newY].state == State::EMPTY) &&
                (newX <= grid[currX][currY].contents->getInfo().x + 1) &&
                (newX >= grid[currX][currY].contents->getInfo().x - 1) &&
                (newY <= grid[currX][currY].contents->getInfo().y + 1) &&
                (newY >= grid[currX][currY].contents->getInfo().y - 1)) {
                grid[newX][newY].state = State::ENEMY;
                g.updateViews(newX, newY, grid[newX][newY].contents ? grid[newX][newY].contents->getInfo().symbol : grid[newX][newY].symbol);
                //grid[newX][newY].contents = grid[currX][currY].contents;
                //grid[currX][currY].contents.reset();
                grid[currX][currY].state = State::EMPTY;
                //g.updateViews(currX, currY, grid[currX][currY].contents ? grid[currX][currY].contents->getInfo().symbol : grid[currX][currY].symbol);
                break;
            }
        }
    }
}

Info Floor::newXY(int currX, int currY, Action a) {
    int newX = currX;
    int newY = currY;
    if (a == Action::NO) newY -= 1;
    if (a == Action::EA) newX += 1;
    if (a == Action::WE) newX -= 1;
    if (a == Action::SO) newY += 1;
    if (a == Action::NE) {newY -= 1; newX += 1;}
    if (a == Action::NW) {newX -= 1; newY -= 1;}
    if (a == Action::SE) {newX += 1; newY += 1;}
    else {newX -= 1; newY += 1;} // SW
    return Info{newX, newY, '#'};
}

void Floor::action(Action a, Action b) {
    int currX = g.getPlayer()->getInfo().x;
    int currY = g.getPlayer()->getInfo().y;
    int newX = newXY(currX, currY, a).x;
    int newY = newXY(currX, currY, a).y;
    if (a == Action::USE) {
        if ((grid[newX][newY].contents) && (grid[newX][newY].state == State::ITEM)) {
            dynamic_pointer_cast<Item>(grid[newX][newY].contents)->use(g.getPlayer());
            updateArgs("Potion consumed");
            grid[newX][newY].contents = nullptr;
            g.updateViews(newX, newY, grid[newX][newY].symbol);
        } else {
            updateArgs("There's nothing to use");
        }
    } else if (a == Action::ATTACK) {
        if ((grid[newX][newY].contents) && (grid[newX][newY].state == State::ENEMY)){
            g.getPlayer()->attack(dynamic_pointer_cast<Character>(grid[newX][newY].contents));
            if (dynamic_pointer_cast<Character>(grid[newX][newY].contents)->getHP() <= 0) {
                g.getPlayer()->addGold(dynamic_pointer_cast<Enemy>(grid[newX][newY].contents)->giveGold()); // use the gold given by enemy
                grid[newX][newY].contents = nullptr;
                g.updateViews(newX, newY, grid[newX][newY].symbol);
                updateArgs("Enemy Slained");
            } updateArgs("PC Attacked");
        } else {
            updateArgs("There's nothing to attack");
        }
    }
}

void Floor::move(Action a) {
    int currX = g.getPlayer()->getInfo().x;
    int currY = g.getPlayer()->getInfo().y;
    int newX = newXY(currX, currY, a).x;
    int newY = newXY(currX, currY, a).y;

    if ((grid[newX][newY].contents) || (grid[newX][newY].terrain == Terrain::SPACE) || (grid[newX][newY].terrain == Terrain::WALL)) {
        updateArgs("Cannot go that way");
    }
    else {
        g.getPlayer()->setPos(newX, newY);
        grid[newX][newY].contents = grid[currX][currY].contents;
        grid[newX][newY].state = State::PLAYER;
        grid[currX][currY].state = State::EMPTY;
        grid[currX][currY].contents = nullptr;
        g.updateViews(newX, newY, '@');
        g.updateViews(currX, currY, '.');
        moveEnemies();
    }
}

void Floor::updateArgs(string s) {
    g.updateViews(g.getRace(), g.getPlayer()->getGold(), floorNum, g.getPlayer()->getHP(), g.getPlayer()->getAtk(), g.getPlayer()->getDDef(), s);
    //g.updateViews(string race, int gold, int floor, int HP, int atk, int def, std::string action)
}

void Floor::readTerrain() {
    ifstream ifs;
    ifs.open("cc3kterrain.txt");
    char curr;
    for(int row = 0; row < gridHeight; row++)  {
            for(int col = 0; col < gridWidth; col++){
                ifs >> noskipws;
                ifs >> curr;
                if (ifs.bad()) throw InvalidFloorExn();
                if (curr == '|') {grid.at(col).at(row).terrain = Terrain::WALL;}
                else if (curr == '-') {grid.at(col).at(row).terrain = Terrain::WALL;}
                else if (curr == '.') {grid.at(col).at(row).terrain = Terrain::DOT;}
                else if (curr == '#') {grid.at(col).at(row).terrain = Terrain::PATH;}
                else if (curr == '+') {grid.at(col).at(row).terrain = Terrain::PLUS;}
                else if (curr == ' ') {grid.at(col).at(row).terrain = Terrain::SPACE;}
                else {grid.at(col).at(row).terrain = Terrain::SPACE;}

                grid.at(col).at(row).symbol = curr;
                //cout << grid.at(col).at(row).symbol;
                g.updateViews(col, row, grid.at(col).at(row).symbol);
            }
    } cout <<endl;
    ifs.close();
}

void Floor::floorFromFile(string filename) {
    ifstream ifs;
    ifs.open(filename);
    char curr;
        for(int row = 0; row < gridHeight; row++)  {
            for(int col = 0; col < gridWidth; col++){
                ifs >> noskipws;
                ifs >> curr;
                if (ifs.bad()) throw InvalidFloorExn();
                switch (curr) {
                    case '0' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "RH");
                    } case '1' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "BA");
                    } case '2' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "BD");
                    } case '3' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "PH");
                    } case '4' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "WA");
                    } case '5' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "WD");
                    } case '6' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "normalH");
                    } case '7' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "smallH");
                    } case '8' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "merchantH");
                    } case '9' : {
                        grid[col][row].contents = PotionFactory::generate(col, row, "dragonH");
                    }  case 'V' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "vampire");
                    }  case 'W' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "werewolf");
                    }  case 'N' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "goblin");
                    }  case 'M' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "merchant");
                    }  case 'D' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "dragon");
                    }  case 'X' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "phoenix");
                    }  case 'T' : {
                        grid[col][row].contents = EnemyFactory::generate(col, row, "troll");
                    }  case '@' : {
                        playerLocX = col;
                        playerLocY = row;
                    }  case '/' : {
                        grid[col][row].contents = std::make_shared<Stair>(col, row);
                    }  default : {}
                }
                grid[col][row].state = State::ITEM;
                g.updateViews(col, row, grid[col][row].contents ? grid[col][row].contents->getInfo().symbol : grid[col][row].symbol);
            }
        }
}

// for random selection and choices
void Floor::makeChambers() {
    // Hard coding chambers
    // first chamber
    for(int i = 3; i <= 6; i++) {
        for(int j = 3; j <= 28; j++) {
            chambers[0].addToChamber(&grid[j][i]);
        }
    }

    // second chamber
    for(int i = 15; i <= 21; i++) {
        for(int j = 4; j <= 24; j++) {
            chambers[1].addToChamber(&grid[j][i]);
        }
    }

    // third chmaber
    for(int i = 3; i <= 4; i++) {
        for(int j = 39; j <= 61; j++) {
            chambers[2].addToChamber(&grid[j][i]);
        }
    }
    for(int j = 39; j <= 69; j++) {
            chambers[2].addToChamber(&grid[j][5]);
        }

    for(int j = 39; j <= 72; j++) {
            chambers[2].addToChamber(&grid[j][6]);
        }

    for(int i = 7; i <= 12; i++) {
        for(int j = 61; j <= 75; j++) {
            chambers[2].addToChamber(&grid[j][i]);
        }
    }

    // Fourth Chmaber
    for(int i = 10; i <= 12; i++) {
        for(int j = 38; j <= 49; j++) {
            chambers[3].addToChamber(&grid[j][i]);
        }
    }

    // fifth chamber
    for(int i = 16; i <= 18; i++) {
        for(int j = 65; j <= 75; j++) {
            chambers[4].addToChamber(&grid[j][i]);
        }
    }

    for(int i = 19; i <= 21; i++) {
        for(int j = 37; j <= 75; j++) {
            chambers[4].addToChamber(&grid[j][i]);
        }
    }
    // end
}
