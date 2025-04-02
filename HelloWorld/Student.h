#pragma once
#include <string>

void f();

class Student {
public:
	Student() {}
	Student(std::string name) { this-> name = name; }

	void Write();
	std::string GetName() { return name; }
	void SetName(std::string name) { this->name = name; }

private:
	std::string name;
};