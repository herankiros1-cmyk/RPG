#include "../include/Character.h"
#include <iostream>
#include <algorithm>

// Constructor
Character::Character(std::string name, int health, int attackPower)
    : name(name), health(health), maxHealth(health), attackPower(attackPower), x(0), y(0) {
    std::cout << "Character " << name << " created" << std::endl;
}

// Virtual destructor
Character::~Character() {
    std::cout << "Character " << name << " destroyed" << std::endl;
}

// Take damage (shared by all derived types)
void Character::takeDamage(int damage) {
    health = std::max(0, health - damage);
    std::cout << name << " takes " << damage << " damage!" << std::endl;
}

// Basic display status (can be overridden)
void Character::displayStatus() const {
    std::cout << "[" << name << "] - HP: " << health << "/" << maxHealth << std::endl;
}

// Alive check
bool Character::isAlive() const {
    return health > 0;
}

// Position methods
void Character::setPosition(int x_coord, int y_coord) {
    x = x_coord;
    y = y_coord;
}

int Character::getX() const { return x; }
int Character::getY() const { return y; }

// Getters
std::string Character::getName() const { return name; }
int Character::getHealth() const { return health; }
int Character::getMaxHealth() const { return maxHealth; }
