#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};

void Square(int& i) {
	i = i * i;
}

void Double(int* i) {
	*i = *i * 2;
}


int main()
{
	// ** REFERENCE **
	int num = 5;
	int& ref = num;
	cout << "num: " << num << endl;
	ref = 10;
	cout << "num: " << num << endl;
	// The int variable's changed to 10 when the refrecne changed.

	cout << "num address: " << &num << endl;
	cout << "ref address: " << &ref << endl;
	// The addresses are the same.

	// ** REFERENCE PARAMETER **
	Square(num);
	cout << "num: " << num << endl;

	// ** POINTER VARIABLE **
	int* ptr = nullptr;
	ptr = &num;
	cout << "Pointer Value (address): " << ptr << endl;
	// This address is the address of the int variable num.
	cout << "Dereference Pointer Value: " << *ptr << endl;

	// ** POINTER PARAMETER **
	Double(ptr);
	cout << "Derefrenced pointer after Double: " << *ptr << endl;
	cout << "num after Double: " << num << endl;
	// Yes, the int variable's value changed when using the pointer.
}
