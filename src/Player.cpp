#include "../include/Player.h"
#include <iostream>

// Constructor – calls Character base class
Player::Player(std::string name, int health, int attackPower)
    : Character(name, health, attackPower),
      inventory(10),           // default capacity 10
      level(1),
      experience(0),
      expToNextLevel(50)
{
    // nothing else
}

// Destructor
Player::~Player() {
    std::cout << "Player " << name << " has left the game." << std::endl;
}

// takeDamage uses base then prints game over if dead
void Player::takeDamage(int damage) {
    Character::takeDamage(damage);
    if (health <= 0) {
        std::cout << "Game Over! " << name << " has fallen..." << std::endl;
    }
}

// displayStatus prints current stats
void Player::displayStatus() const {
    std::cout << "[Player] " << name
              << " | HP: " << health << "/" << maxHealth
              << " | ATK: " << getAttackPower()
              << " | LVL: " << level
              << " | EXP: " << experience << "/" << expToNextLevel
              << std::endl;
}

// Gain EXP and handle leveling
void Player::gainExp(int exp) {
    experience += exp;
    std::cout << name << " gains " << exp << " EXP!" << std::endl;
    while (experience >= expToNextLevel) {
        levelUp();
    }
}

// Level-up logic
void Player::levelUp() {
    experience -= expToNextLevel;
    level++;

    maxHealth += 10;
    health = maxHealth;
    attackPower += 2;
    expToNextLevel = level * 50;

    std::cout << "LEVEL UP! " << name << " is now level " << level << "!\n";
    displayStatus();
}

// Show inventory
void Player::showInventory() const {
    std::cout << "--- " << name << "'s Inventory ---" << std::endl;
    inventory.display();
}

// operator+= to add item to player's inventory (used by Map)
Player& Player::operator+=(const Item& item) {
    if (inventory.addItem(item)) {
        std::cout << name << " found a " << item << std::endl;
    } else {
        std::cout << name << "'s inventory is full! Could not add " << item << std::endl;
    }
    return *this;
}

// Getters
int Player::getLevel() const {
    return level;
}

int Player::getExp() const {
    return experience;
}

// IMPORTANT: attack power = base + inventory weapon bonuses
int Player::getAttackPower() const {
    return attackPower + inventory.getTotalAttackBonus();
}
