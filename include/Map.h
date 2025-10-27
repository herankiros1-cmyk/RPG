#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "NPC.h"

/**
 * Map manages the game world layout and handles player movement and interactions.
 * It tracks positions of items, enemies, and NPCs on the grid.
 */
class Map {
private:
    int width, height;
    std::vector<std::string> grid;
    Player* player;

    struct MapItem {
        int x, y;
        Item item;
    };
    std::vector<MapItem> items;

public:
    Map(int width, int height, Player* player);

    void addItem(int x, int y, const Item& item);
    void draw(const std::vector<Enemy*>& enemies, const std::vector<NPC*>& npcs) const;
    void movePlayer(char input);

private:
    bool isInside(int x, int y) const;
    bool isWall(int x, int y) const;
};

#endif
