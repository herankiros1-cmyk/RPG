# Implementation Plan

## Feature 1: Start Game
**Trigger:** User chooses **"Start Game"** from the menu.  
**Input Needed:** None (uses default player and enemies).  
**Implementation Flow:**
1. `main()` receives choice 1 and calls `game.run()`.
2. `Game::run()` starts the game loop, showing player and enemy status.
3. Combat and events happen (future updates will expand this).  
   **Data Modified:** Player HP, enemy HP.  
   **Completion:** Returns to main menu when combat ends.  
   **Functions Used:** `Game::run()`, `Player::displayStatus()`, `Enemy::attack()`.

---

## Feature 2: Show Inventory
**Trigger:** User chooses **"Show Inventory"** from the menu.  
**Input Needed:** None.  
**Implementation Flow:**
1. `main()` detects choice 2.
2. Calls `player->showInventory()` (to be linked later).
3. Displays all item names and bonuses from `Inventory::display()`.  
   **Data Modified:** None (read-only).  
   **Completion:** Returns to menu after printing.  
   **Functions Used:** `Inventory::display()`, `Item::getName()`.

---

## Feature 3: Combat System
**Trigger:** Game encounter inside `Game::run()`.  
**Input Needed:** Player and Enemy stats.  
**Implementation Flow:**
1. Enemy attacks player → `Enemy::attack(Character&)`.
2. Player takes damage → `Character::takeDamage(int)`.
3. If player wins → `Player::gainExp(int)` and enemy deleted.  
   **Data Modified:** Player health and EXP.  
   **Completion:** Prints results, continues game loop.  
   **Functions Used:** `Enemy::attack()`, `Player::takeDamage()`, `Player::gainExp()`.

---

## Feature 4: NPC Interaction
**Trigger:** Player meets NPC in game map.  
**Input Needed:** None (dialogue lines pre-set).  
**Implementation Flow:**
1. `Game::run()` detects proximity to NPC.
2. Calls `npc->talk()`.
3. Prints each dialogue line in order.  
   **Data Modified:** None.  
   **Completion:** Returns to map after conversation.  
   **Functions Used:** `NPC::talk()`, `NPC::displayStatus()`.

---

## Feature 5: Save and Load Game
**Trigger:** User selects "Save and Quit".  
**Input Needed:** File name or auto-save path.  
**Implementation Flow:**
1. `Game::saveToFile(filename)` writes player stats and inventory.
2. On startup, `Game::loadFromFile(filename)` restores data.  
   **Data Modified:** Save file data.  
   **Completion:** Player can continue from previous progress.  
   **Functions Used:** `Game::saveToFile()`, `Game::loadFromFile()`.

---

## Feature 6: Level Up System
**Trigger:** Player gains enough EXP to reach next level.  
**Input Needed:** EXP value and threshold.  
**Implementation Flow:**
1. `Player::gainExp()` checks if `exp >= expToNextLevel`.
2. If true → `Player::levelUp()`.
3. Increase level and attack power; reset EXP bar.  
   **Data Modified:** Player level, EXP, attack stats.  
   **Completion:** Displays “Level Up!” message.  
   **Functions Used:** `Player::gainExp()`, `Player::levelUp()`.
