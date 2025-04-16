#include "Cat.h"
#include <iostream>

using namespace std;

void Cat::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);
	ostream << "Enter number of lives: ";
	istream >> lives;
	istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Cat::Write(std::ostream& ostream) const
{
	Animal::Write(ostream);
	ostream << "Number of lives: " << lives << std::endl;
}