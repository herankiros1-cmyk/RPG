#include "../include/Enemy.h"
#include <iostream>

int main() {
    // Create an Enemy
    Enemy goblin("Goblin", 50, 10, 20, 'G');

    // Display its status
    goblin.displayStatus();

    // Simulate a player attacking the goblin multiple times
    std::cout << "\nPlayer attacks Goblin for 15 damage!\n";
    goblin.takeDamage(15);
    goblin.displayStatus();


    std::cout << "\nPlayer attacks Goblin for 20 damage!\n";
    goblin.takeDamage(20);
    goblin.displayStatus();

    std::cout << "\nPlayer attacks Goblin for 30 damage!\n";
    goblin.takeDamage(30);
    goblin.displayStatus();

    return 0;
}
