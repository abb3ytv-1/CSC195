#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

void arrayExample() {
	cout << "=== Array Example ===" << endl;

	array<string, 7> days = { "Monday", "Tuesday", "Wednesday", "Thursady", "Friday", "Saturday", "Sunday" };

	cout << "Days of the week:" << endl;
	for (const auto& day : days) {
		cout << day << endl;
	}
	cout << endl;
}

void vectorExample() {
	cout << "=== Vector Example ===" << endl;

	vector<int> numbers{ 10, 20, 30, 40, 50 };

	numbers.push_back(60);
	numbers.push_back(70);

	numbers.pop_back();

	cout << "Vector contents:" << endl;
	for (size_t i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl << endl;
}

void listExample() {
	cout << "=== List Example ===" << endl;

	list<string> charecters = { "James", "Peter", "Sirius", "Remus", "Lily", "Marlene" };

	charecters.push_front("Harry");
	charecters.push_back("Draco");

	charecters.remove("Peter");

	cout << "Charectets List:" << endl;
	for (auto it = charecters.begin(); it != charecters.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl;
}

void mapExample() {
	cout << "=== Map Example ===" << endl;
	map<string, int> ages;
	ages["Alice"] = 30;
	ages["Bob"] = 25;
	ages["Charlie"] = 35;
	ages["Alice"] += 1; 
	cout << "Ages of characters:" << endl;
	for (const auto& pair : ages) {
		cout << pair.first << ": " << pair.second << " years old" << endl;
	}
	cout << endl;
}



int main()
{
	arrayExample();
	vectorExample();
	listExample();
	mapExample();

	return 0;
}
