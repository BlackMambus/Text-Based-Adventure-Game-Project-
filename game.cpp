#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
    bool hasKey = false;
    bool isAlive = true;
};

void intro() {
    cout << "🧙 Welcome to the Dungeon of Doom!\n";
    cout << "You wake up in a dark room with two doors.\n";
}

void room1(Player& player);
void room2(Player& player);
void treasureRoom(Player& player);

void room1(Player& player) {
    cout << "\nYou enter Room 1. It's quiet... too quiet.\n";
    cout << "You see a shiny key on the floor.\n";
    cout << "Do you pick it up? (yes/no): ";
    string choice;
    cin >> choice;

    if (choice == "yes") {
        player.hasKey = true;
        cout << "You picked up the key.\n";
    } else {
        cout << "You leave the key behind.\n";
    }

    cout << "You return to the starting room.\n";
}

void room2(Player& player) {
    cout << "\nYou enter Room 2. A monster appears! 🐉\n";
    if (player.hasKey) {
        cout << "You use the key to unlock a hidden door and escape!\n";
        treasureRoom(player);
    } else {
        cout << "You have nothing to defend yourself with...\n";
        cout << "The monster attacks you. You died. 💀\n";
        player.isAlive = false;
    }
}

void treasureRoom(Player& player) {
    cout << "\nYou find a hidden treasure room filled with gold! 🪙\n";
    cout << "Congratulations, you win!\n";
    player.isAlive = false;
}

int main() {
    Player player;
    intro();

    while (player.isAlive) {
        cout << "\nChoose a door:\n";
        cout << "1. Go to Room 1\n";
        cout << "2. Go to Room 2\n";
        cout << "3. Quit Game\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: room1(player); break;
            case 2: room2(player); break;
            case 3: cout << "Thanks for playing!\n"; player.isAlive = false; break;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
