#pragma once
#include <vector>
#include "Animal.h"

class Database {
public:
	~Database();

	void Create(Animal::eType type);
	void DisplayAll() const;
	void Display(const std::string& name) const;
	void Display(Animal::eType type) const;

private:
	std::vector<Animal*> animals;
};