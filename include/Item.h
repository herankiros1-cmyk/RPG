#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

// Item types
enum ItemType {
    CONSUMABLE,
    WEAPON,
    ARMOR,
    QUEST_ITEM
};

/**
 * Enemy represents hostile characters that the player can fight.
 * It includes combat behavior and experience rewards.
 */
class Item {
private:
    static int totalItems;
    std::string name;
    int value;
    ItemType type;
    int attackBonus;
public:
    Item(std::string name = "Scrap", int value = 0,
         ItemType type = CONSUMABLE, int attackBonus = 0);

    std::string getName() const { return name; }
    int getValue() const { return value; }
    ItemType getType() const { return type; }
    int getAttackBonus() const { return attackBonus; }

    static int getTotalItems();
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

#endif
