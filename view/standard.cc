#include "standard.h"

Standard::Standard(Game& g): game{g}, out{std::cout}{

    for (size_t c = 0; c < 80; c++) {
        std::vector<char> cellCol;
        for (size_t r = 0; r < 25; r++) {
            cellCol.emplace_back(' ');
        }
        display.emplace_back(cellCol);
    }
}

void Standard::updateView() {

for (size_t c = 0; c < 25; c++) {
        for (size_t r = 0; r < 80; r++) {
            out << display[r][c];
        }
        
}
}

void Standard::update(const std::string& msg) {}

void Standard::update(int col, int row, char disp) {
  display.at(col).at(row) = disp;
}

void Standard::update(std::string race, int gold, int floor, int HP, int atk, int def, std::string action) {} // do nothing
