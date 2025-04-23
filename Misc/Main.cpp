#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;
using names_t = vector<string>;



namespace math {
	template <typename T1, typename T2>
	T1 Max(T1 a, T2 b) {
		return (a > b) ? a : b;

		//if (a > b) {
	//	return a;
	//} else {
	//	return b;
	//}
	}
}

void print(const names_t names) {
	//names[0] = "Harry";
	for (string name : names) {
		cout << name << endl;
	}
}

int main() {
	math::ipoint_t p1(10, 20);
	math::ipoint_t p2(30, 40);
	math::ipoint_t p3(50, 60);
	//p3 = p1.Add(p2);
	p3 = p1 + p2;
	p3 = p2 - p1;

	

	//cout << p1.Add(p2).GetX() << endl;
	cout << p3.GetX() << " " << p3.GetY() << endl;

	//cout << max(5, 10) << endl;
	//cout << math::Max(6.0, 10.0f) << endl;

	names_t names{ "James", "Remus", "Sirius"};
	print(names);
}

