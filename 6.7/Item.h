#ifndef ITEM_H
#define ITEM_H


class Item {
public:
    Item(int value) : value(value) {}
    int getValue() const { return value; }
private:
    int value;
};

#endif // ITEM_H
