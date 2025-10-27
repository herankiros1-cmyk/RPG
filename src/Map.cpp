#include "../include/Map.h"
#include "../include/Player.h"
#include <iostream>

Map::Map(int width, int height, Player* player)
    : width(width), height(height), player(player) {
    grid.resize(height);
    for (int r = 0; r < height; ++r) {
        grid[r].resize(width, '.');
        for (int c = 0; c < width; ++c) {
            if (r == 0 || r == height - 1 || c == 0 || c == width - 1) grid[r][c] = '#';
            else grid[r][c] = '.';
        }
    }
}

void Map::addItem(int x, int y, const Item& item) {
    MapItem mi{ x, y, item };
    items.push_back(mi);
}

bool Map::isInside(int x, int y) const {
    return x >= 0 && y >= 0 && x < width && y < height;
}

bool Map::isWall(int x, int y) const {
    if (!isInside(x, y)) return true;
    return grid[y][x] == '#';
}

void Map::draw(const std::vector<Enemy*>& enemies, const std::vector<NPC*>& npcs) const {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            // player
            if (player->getX() == col && player->getY() == row) {
                std::cout << '@';
                continue;
            }
            bool drawn = false;
            // enemies
            for (size_t i = 0; i < enemies.size(); ++i) {
                if (enemies[i]->isAlive() && enemies[i]->getX() == col && enemies[i]->getY() == row) {
                    std::cout << enemies[i]->getSymbol();
                    drawn = true;
                    break;
                }
            }
            if (drawn) continue;
            // npcs
            for (size_t i = 0; i < npcs.size(); ++i) {
                if (npcs[i]->getX() == col && npcs[i]->getY() == row) {
                    std::cout << 'N';
                    drawn = true;
                    break;
                }
            }
            if (drawn) continue;
            // item marker (optional) - show 'M' for merchant tile or '!' for item
            bool itemHere = false;
            for (const auto& it : items) {
                if (it.x == col && it.y == row) { std::cout << '!'; itemHere = true; break; }
            }
            if (itemHere) continue;
            // tile
            std::cout << grid[row][col];
        }
        std::cout << '\n';
    }
}

void Map::movePlayer(char direction) {
    int x = player->getX();
    int y = player->getY();

    switch (direction) {
        case 'w': y--; break;
        case 's': y++; break;
        case 'a': x--; break;
        case 'd': x++; break;
        default: break;
    }

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= width) x = width - 1;
    if (y >= height) y = height - 1;

    // move if not wall
    if (!isWall(x, y)) {
        player->setPosition(x, y);
        // pick up items
        for (auto it = items.begin(); it != items.end(); ) {
            if (it->x == x && it->y == y) {
                player->operator+=(it->item);
                it = items.erase(it);
            } else ++it;
        }
    } else {
        std::cout << "Can't move there - it's a wall!\n";
    }
}
