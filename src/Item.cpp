#include "../include/Item.h"

int Item::totalItems = 0;

Item::Item(std::string name, int value, ItemType type, int attackBonus)
    : name(name), value(value), type(type), attackBonus(attackBonus) {
    totalItems++;
    if (type == WEAPON) {
        std::cout << "Weapon created: " << name << " (+" << attackBonus << " ATK)\n";
    } else {
        std::cout << "An item was created: " << name << "\n";
    }
}

int Item::getTotalItems() {
    return totalItems;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.name;
    if (item.type == WEAPON) os << " (Weapon +" << item.attackBonus << " ATK)";
    else os << " (Value: " << item.value << ")";
    return os;
}
