#include "Student.h"
#include <iostream>
using namespace std;

class Person {
public:
    float weight;
    std::string name;
	int age;

    void f() {}
};

int main() {
    Student student;
	student.SetName("Sirius Black");
	student.Write();

	Person person;
    person.age = 36;

    unsigned int i = 36;
	std::cout << i << std::endl;
	std::cout << sizeof(char) << std::endl;
	std::cout << sizeof(Person) << std::endl;
	std::cout << (char)i << std::endl;

    //cout << i << endl;

	char c = 'A';
    cout << (int)c << std::endl;
	std::cout << c << std::endl;

    f();
        
    cout << "Hello, World!" << endl;
    cout << "Git is now tracking this project!" << endl;

    return 0;
}