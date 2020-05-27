#ifndef __CELL__
#define __CELL__
#include "./state.h"
#include <memory>

class Subject;

class Cell
{

public:
    int posX, posY;
    char symbol;
    Terrain terrain = Terrain::SPACE;
    State state = State::EMPTY;
    std::shared_ptr<Subject> contents;// = std::nullptr;
    Cell(int x, int y) : posX{x}, posY{y} {}
};

#endif
