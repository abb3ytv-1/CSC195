#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) const override;
	eType GetType() const override { return eType::CAT; }

private:
	int lives;
};