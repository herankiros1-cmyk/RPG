#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

/**
 * Inventory class manages a dynamic collection of items.
 * It allows adding items, displaying them, and calculating total attack bonus.
 */
class Inventory {
private:
    Item* items;      // dynamic array of Items
    int capacity;
    int itemCount;

public:
    Inventory(int capacity);                 // constructor
    ~Inventory();                            // destructor
    Inventory(const Inventory& other);       // copy constructor
    bool addItem(const Item& item);          // add an item
    void display() const;                    // show all items


    int getTotalAttackBonus() const;
};

#endif
