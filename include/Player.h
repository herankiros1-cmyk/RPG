#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Character.h"
#include "Inventory.h"
#include "Item.h"

/** Player represents the main controllable character in the game.
 * It handles combat stats, leveling up, experience, and inventory management.
 */
class Player : public Character {
private:
    Inventory inventory;
    int level;
    int experience;
    int expToNextLevel;

public:
    // Constructor
    Player(std::string name, int health, int attackPower);

    // Destructor
    ~Player();

    // Combat / status
    void takeDamage(int damage) override;
    void displayStatus() const override;

    // Attack power includes inventory bonuses
    int getAttackPower() const override;

    // Leveling system
    void gainExp(int exp);
    void levelUp();

    // Inventory
    void showInventory() const;
    Player& operator+=(const Item& item); // supports player += item

    // Getters
    int getLevel() const;
    int getExp() const;
};

#endif
