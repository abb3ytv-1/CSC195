#include "Employee.h"

const float Employee::TAX = 0.1f;

void Employee::Read() {
	std::cout << "Enter name: ";
	std::cin >> name;

	std::cout << "Enter age: ";
	std::cin >> age;

	std::cout << "Enter zipcode: ";
	std::cin >> zipcode;

	std::cout << "Enter wage: ";
	std::cin >> wage;

	std::cout << "Enter hours worked: ";
	std::cin >> hoursWorked;
}