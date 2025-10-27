#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include <vector>
#include <string>
/**
 *NPC represents non-playable characters that can interact with the player.
 *They provide dialogue and story elements but do not engage in combat.
 */
// NPC class inherits from Character
class NPC : public Character {
private:
    std::vector<std::string> dialogue; // Lines of dialogue the NPC can say

public:
    // Constructor
    NPC(std::string name, std::vector<std::string> dialogueLines);

    // Destructor
    ~NPC();

    // Override pure virtual function (NPCs don't attack)
    int getAttackPower() const override;

    // Override displayStatus
    void displayStatus() const override;

    // NPC specific function to talk
    void talk() const;
};

#endif
