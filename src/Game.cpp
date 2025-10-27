#include "../include/Game.h"
#include "../include/NPC.h"
#include <iostream>

Game::Game() {
    player = new Player("Hero", 100, 15);
    enemies.push_back(new Enemy("Goblin", 50, 8, 30));
    enemies.push_back(new Enemy("Orc", 80, 12, 50));

    std::vector<std::string> lines = {
        "Welcome to our village!",
        "Be careful out there."
    };
    npcs.push_back(new NPC("Villager", lines));
}

Game::~Game() {
    delete player;
    for (auto e : enemies) delete e;
    for (auto n : npcs) delete n;
}

void Game::run() {
    std::cout << "=== Game Running ===" << std::endl;
    player->displayStatus();
    enemies[0]->attack(*player);
    player->displayStatus();
}
