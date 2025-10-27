#include "../include/Enemy.h"
#include <iostream>

Enemy::Enemy(std::string name, int health, int attackPower, int rewardExp, char symbol)
    : Character(name, health, attackPower), rewardExp(rewardExp), symbol(symbol) {
    std::cout << "Enemy " << name << " appears!" << std::endl;
}

Enemy::~Enemy() {
    std::cout << "Enemy " << name << " has been defeated." << std::endl;
}

int Enemy::getAttackPower() const {
    return attackPower;
}

void Enemy::displayStatus() const {
    std::cout << "[Enemy] " << name
              << " | HP: " << health << "/" << maxHealth
              << " | ATK: " << attackPower
              << " | EXP reward: " << rewardExp
              << std::endl;
}

void Enemy::attack(Character& target) {
    std::cout << name << " attacks " << target.getName()
              << " for " << attackPower << " damage!" << std::endl;
    target.takeDamage(attackPower);
}

int Enemy::getRewardExp() const {
    return rewardExp;
}
