#ifndef ITEM_H
#define ITEM_H

class Item : public Subjuct{
    char sym;
public:
    Item(int x, int y, char sym);
    virtual ~Item()=0;
};
