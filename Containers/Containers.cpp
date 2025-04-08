#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

unsigned int GetHash(std::string str) {
	unsigned int hash = 0;
	for (char c : str) {
		hash = hash * 31 + (int)c;
	}
	return hash;
}

int main() {

	// Array
	cout << "=== ARRAY ===" << endl;
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	cout << arr.size() << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	// vector
	cout << "=== VECTOR ===" << endl;
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vec.push_back(6);

	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	s.push(5);
	cout << s.top() << endl;

	// List
	cout << "=== LIST ===" << endl;
	list<int> lst = { 1, 2, 3, 4, 5 };
	lst.push_back(6);
	lst.insert(lst.begin(), 0);

	cout << lst.size() << endl;

	// Map (ordered map)
	cout << "=== MAP ===" << endl;
	map<string, int> m;
	m["Sirius"] = 10000;
	m["James"] = 200000;
	m["Lily"] = 300;

	cout << m["Lily"] << endl;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	// unordered map
	cout << "=== UNORDERED MAP ===" << endl;
	unordered_map<string, string> um;
	um["Sirius"] = "Black";
	um["James"] = "Potter";
	um["Lily"] = "Evans";

	cout << um["Sirius"] << endl;

	cout << "=== Hash Name ===" << endl;
	string name = "Regulus";
	int hash = GetHash(name);
	cout << name << endl;
	cout << hash << endl;

	int data[10];
	data[hash % 10] = 84651;

	hash = GetHash("Lily");
	cout << data[hash % 10] << endl;


	//cout << &i << endl;
	//cout << (&arr[0]) << endl;
	//cout << (&arr[1]) << endl;

	return 0;
}
