#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

/**
 * Character is the base class for all characters in the game.
 * It defines common attributes and behaviors like health, attack, and position.
 */
class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int x, y;  // Position on the map

public:
    // Base constructor
    Character(std::string name, int health, int attackPower);

    // Virtual destructor (important for inheritance cleanup)
    virtual ~Character();

    // Pure virtual function (makes this an abstract class)
    virtual int getAttackPower() const = 0;

    // Combat
    virtual void takeDamage(int damage);

    // Status
    virtual void displayStatus() const;

    // Check if alive
    bool isAlive() const;

    // Position
    void setPosition(int x, int y);
    int getX() const;
    int getY() const;

    // Getters
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
};

#endif
