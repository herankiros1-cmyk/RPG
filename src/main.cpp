#include <iostream>
#include "../include/Game.h"

using namespace std;

void displayMenu();

int main() {
    Game game;

    bool running = true;
    int choice;

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout <<" Starting the game...\n";
                game.run();
                break;
            case 2:
                cout<<"Showing inventory (feature to implement)...\n";
                //TODO: Call inventory display function here
                break;
            case 3:
                cout<<"Exiting the game. Goodbye!\n";
                running = false;
                break;
        default:
           cout << "Invalid choice. Please try again.\n";

        }
    }
return 0;
}
void displayMenu(){
cout << "\n=== RPG Game ===" << endl;
cout << "1. Start the game" << endl;
cout << "2. Showing inventory" << endl;
cout << "3. Exit" << endl;
cout << "Choice: ";
}