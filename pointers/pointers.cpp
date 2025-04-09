#include <iostream>

using namespace std;

void func1() {
    bool b = true;
    int i = 5;
}

void func2() {
    bool b = false;
    float f = 10;

    func1();
}

void func3() {
    int i[1000000];
    func3();
}

class Animal {
public:
    Animal(string name) {
        m_name = name;
    }

	string getName() {
		return m_name;
	}

private:
    string m_name;
};

int main()
{
    int i = 5;
    float f = 4.5f;

    //func2();
    //func3();
    {
        int* p = new int(5);
        std::cout << *p << endl;
        delete p;
    }

	Animal* dog = new Animal("Padfoot");
	Animal* cat = new Animal("Binx");

	cout << dog->getName() << endl;
	cout << cat->getName() << endl;

	delete dog;
	delete cat;
	dog = nullptr;
	if (dog == nullptr) {
		cout << "Dog is null" << endl;
	}

	int* block = (int*)malloc(sizeof(int) * 1000);
    block[0] = 3;
	block[1] = 4;
	block[2] = 5;
	block[3] = 6;

    block++;
	cout << *(block + 2) << endl;
	free(--block);
}

