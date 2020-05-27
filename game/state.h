#ifndef __STATE__
#define __STATE__

enum class Terrain {WALL, SPACE, DOT, PLUS, PATH};
enum class State {EMPTY, ENEMY, ITEM, PLAYER};
enum class Action { INVALID = 0, NO, SO, EA, WE, NW, NE, SW, SE,  NONE, ATTACK, USE};
enum class Dir {NO = 0, SO, EA, WE, NW, NE, SW, SE};

struct Info {
    int x;
    int y;
    char symbol;
};

#endif
