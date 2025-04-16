#include "Dog.h"
#include <iostream>

void Dog::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);
	ostream << "Enter breed: ";
	std::getline(istream, breed);
}

void Dog::Write(std::ostream& ostream) const
{
	Animal::Write(ostream);
	ostream << "Breed: " << breed << std::endl;
}
