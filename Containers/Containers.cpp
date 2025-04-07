#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>
using namespace std;

int main() {

	// Array
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	cout << arr.size() << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	// vector
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vec.push_back(6);

	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	// List
	list<int> lst = { 1, 2, 3, 4, 5 };
	lst.push_back(6);
	lst.insert(lst.begin(), 0);

	// Map
	map<string, int> m;
	m["Sirius"] = 100000;
	m["James"] = 200000;
	m["Lily"] = 300;

	cout << m["Lily"] << endl;

	//cout << &i << endl;
	//cout << (&arr[0]) << endl;
	//cout << (&arr[1]) << endl;

	return 0;
}
