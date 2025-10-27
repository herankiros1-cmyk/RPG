#include "../include/Character.h"

int main() {
    Character hero("Hero", 100, 12);
    hero.displayStatus();
    hero.takeDamage(20);
    hero.displayStatus();
    return 0;
}
