#ifndef __CHAMBER__
#define __CHAMBER__
#include <vector>

#include "cell.h"

class Chamber {
private:
    std::vector<Cell*> cells;
    size_t numCell = 0;
    /* data */
public:
    void addToChamber(Cell* c) {
        cells.emplace_back(c);
        numCell += 1;
    }
    int getCells() {return numCell;}
    
    Cell* operator[](int n) {
        return cells.at(n);
    }
};

#endif
