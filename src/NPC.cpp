#include "../include/NPC.h"
#include "../include/Game.h"
#include <iostream>

// Constructor - NPCs have 0 attack power and fixed health
NPC::NPC(std::string name, std::vector<std::string> dialogueLines)
    : Character(name, 50, 0), dialogue(dialogueLines) {
    std::cout << "NPC " << name << " created." << std::endl;
}

// Destructor
NPC::~NPC() {
    std::cout << "NPC " << name << " removed from the world." << std::endl;
}

// NPCs don't attack
int NPC::getAttackPower() const {
    return 0;
}
// Override displayStatus for NPC
void NPC::displayStatus() const {
    std::cout << "NPC: " << name
              << " | HP: " << health << "/" << maxHealth
              << " | (Friendly)" << std::endl;
}

// NPC talks - show dialogue lines
void NPC::talk() const {
    std::cout << name << " says:" << std::endl;
    for (const auto& line : dialogue) {
        std::cout << "  \"" << line << "\"" << std::endl;
    }
}
