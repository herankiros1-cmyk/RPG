#include "../include/Inventory.h"
#include <iostream>

Inventory::Inventory(int capacity) : capacity(capacity), itemCount(0) {
    items = new Item[capacity];  // allocate dynamic array
}

Inventory::~Inventory() {
    delete[] items;              // free memory
    std::cout << "Inventory for destroyed.\n";
}

Inventory::Inventory(const Inventory& other)
    : capacity(other.capacity), itemCount(other.itemCount) {
    items = new Item[capacity];   // new array
    for (int i = 0; i < itemCount; ++i) {
        items[i] = other.items[i]; // deep copy
    }
    std::cout << "COPY CONSTRUCTOR for Inventory called for deep copy.\n";
}

bool Inventory::addItem(const Item& item) {
    if (itemCount < capacity) {
        items[itemCount++] = item;
        return true;
    }
    return false; // inventory full
}

void Inventory::display() const {
    std::cout << "Inventory (" << itemCount << "/" << capacity << "):\n";
    for (int i = 0; i < itemCount; ++i) {
        std::cout << "  " << items[i] << "\n";  // uses friend operator<<
    }
}
int Inventory::getTotalAttackBonus() const {
    int total = 0;
    for (int i = 0; i < itemCount; ++i) {
        if (items[i].getType() == WEAPON) {
            total += items[i].getAttackBonus();
        }
    }
    return total;
}