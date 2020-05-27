#include "textdisplay.h"
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"
#include "cell.h"
using namespace std;
TextDisplay::TextDisplay() {
}

TextDisplay::~TextDisplay() {}


void TextDisplay::update(Subject &whoNotified) {
    int x = whoNotified.getX();
    int y = whoNotified.getY();
    theDisplay[x][y] =  whoNotified.getSym();
}

void TextDisplay::defGrid(vector<char>* display) {
    // first line, last line horizontal
    for (size_t i = 0; i < 25; i++) {
        for (size_t j = 1; j < 78; j++){
            theDisplay[i][0] = '|';
            theDisplay[i][78] = '|';
            theDisplay[1][j] = '-';
            theDisplay[24][j] = '-';
            
        }
    }
}
theDisplay[25] = "Race: " + player.getRace() +
std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    for (size_t i = 0; i < 25; i++){
        for (size_t j = 0; j < 79; j++){
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
    
    out << "Race: " << player.getRace() << "Gold: " << player.gold() << endl;
    out << "HP: " << player.PH << endl;
    out << "Atk: " << player.atk << endl;
    out << "Def: " << player.def << endl;
    
    out << "Action: ";
    return out;
}
