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

void Employee::Write() {
	float weeklyGross = wage * hoursWorked;
	float weeklyTax = weeklyGross * TAX;
	float weeklyNet = weeklyGross - weeklyTax;
	float yearlyGross = weeklyGross * 52;
	float yearlyNet = yearlyGross - (yearlyGross * TAX);

	std::cout << "\nEmployee PayRoll Summary\n";
	std::cout << "-------------------------\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Age: " << age << "\n";
	std::cout << "Zipcode: " << zipcode << "\n";
	std::cout << "Hourly Wage: $" << wage << "\n";
	std::cout << "Hours Worked: " << hoursWorked << "\n";
	std::cout << "Weekly Gross Pay: $" << weeklyGross << "\n";
	std::cout << "Weekly Net Pay: $" << weeklyNet << "\n";
	std::cout << "Yearly Gross Pay: $" << yearlyGross << "\n";
	std::cout << "Yearly Net Pay: $" << yearlyNet << "\n";
}