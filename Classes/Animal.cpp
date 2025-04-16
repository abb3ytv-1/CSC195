#include "Animal.h"


void Animal::Read(std::ostream& ostream, std::istream& istream) {
    ostream << "Enter name: ";
    std::getline(istream, name);

    ostream << "Enter age: ";
    istream >> age;
    istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Animal::Write(std::ostream& ostream) const {
    ostream << "Name: " << name << "\nAge: " << age << std::endl;
}