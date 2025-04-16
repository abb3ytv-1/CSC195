#include <iostream>
#include "Database.h"

int main() {
    Database database;
    bool quit = false;

    while (!quit) {
        std::cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::cout << "Enter type (0 for CAT, 1 for DOG): ";
            int t;
            std::cin >> t;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Animal::eType type = static_cast<Animal::eType>(t);
            database.Create(type);
            break;
        }
        case 2:
            database.DisplayAll();
            break;
        case 3: {
            std::cout << "Enter name: ";
            std::string name;
            std::getline(std::cin, name);
            database.Display(name);
            break;
        }
        case 4: {
            std::cout << "Enter type (0 for CAT, 1 for DOG): ";
            int t;
            std::cin >> t;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            database.Display(static_cast<Animal::eType>(t));
            break;
        }
        case 5:
            quit = true;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    }

    return 0;
}