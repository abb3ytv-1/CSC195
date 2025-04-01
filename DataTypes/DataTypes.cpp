

#include <iostream>
using namespace std;

int main()
{
	std::string name;
	char initial;
	short age;
	bool isAdult;
	unsigned int zipcode;
	float wage;
	short daysWorked;
	float hoursWorkedPerDay[7];

	const float TAX = 0.1f; // 10% tax rate


	// User Input
	cout << "Enter first name: ";
	cin >> name;

	cout << "Enter initial of last name: ";
	cin >> initial;

	cout << "Enter age: ";
	cin >> age;
	isAdult = (age >= 18);  // Determine adulthood status

	cout << "Enter zipcode: ";
	cin >> zipcode;

	cout << "Enter hourly wage: ";
	cin >> wage;

	cout << "Enter number of days worked (max 7): ";
	cin >> daysWorked;



	// Hours Worked Per Day
	float totalHours = 0;

	for (int i = 0; i < daysWorked; i++)
	{
		cout << "Enter hours worked on day " << i + 1 << ": ";
		cin >> hoursWorkedPerDay[i];

		totalHours += hoursWorkedPerDay[i];
	}


	// Calculate Payroll
	float grossIncome = totalHours * wage;
	float taxAmount = grossIncome * TAX;
	float netIncome = grossIncome - taxAmount;

	// Display Payroll Info
	cout << "\nEmployee Payroll Summary\n";
	cout << "-------------------------\n";
	cout << "Name: " << name << " " << initial << ".\n";
	cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
	cout << "Zipcode: " << zipcode << "\n";
	cout << "Hourly Wage: $" << wage << " per hour\n";
	cout << "Total Hours Worked: " << totalHours << " hours\n";
	cout << "Gross Income: $" << grossIncome << "\n";
	cout << "Tax Amount: $" << taxAmount << "\n";
	cout << "Net Income: $" << netIncome << "\n";
}

