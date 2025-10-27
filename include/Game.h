#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "NPC.h"
#include <vector>

/**
 * Game coordinates the entier RPG flow, managing the player, enemies, and interactions.
 * It serves as the main controller for the gameplay loop.
 */
class Game {
private:
    Player* player;
    std::vector<Enemy*> enemies;
    std::vector<NPC*> npcs;

public:
    Game();
    ~Game();
    void run();
};

#endif
