#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

/**
 * Enemy represents hostile characters that the player can fight.
 * It includes combat behavior and experience rewards.
 */
class Enemy : public Character {
private:
    int rewardExp;
    char symbol;

public:
    // Constructor (symbol default '?')
    Enemy(std::string name, int health, int attackPower, int rewardExp, char symbol = '?');

    ~Enemy();

    int getAttackPower() const override;
    void displayStatus() const override;

    void attack(Character& target);
    int getRewardExp() const;

    char getSymbol() const { return symbol; }
};

#endif
