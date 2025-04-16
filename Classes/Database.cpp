#include "Database.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>

Database::~Database() {
    for (auto* animal : animals) {
        delete animal;
        }
    animals.clear();
}

void Database::Create(Animal::eType type) {
    Animal* animal = nullptr;
    switch (type) {
    case Animal::eType::CAT:
        animal = new Cat();
        break;
    case Animal::eType::DOG:
        animal = new Dog();
        break;
    default:
        std::cout << "Invalid animal type." << std::endl;
        return;
    }

    animal->Read(std::cout, std::cin);
    animals.push_back(animal);
}

void Database::DisplayAll() const {
    for (const auto* animal : animals) {
        animal->Write(std::cout);
        std::cout << std::endl;
    }
}

void Database::Display(const std::string& name) const {
    for (const auto* animal : animals) {
        if (animal->GetName() == name) {
            animal->Write(std::cout);
            std::cout << std::endl;
        }
    }
}

void Database::Display(Animal::eType type) const {
    for (const auto* animal : animals) {
        if (animal->GetType() == type) {
            animal->Write(std::cout);
            std::cout << std::endl;
        }
    }
}