#include <iostream>
using namespace std;

void modifyValues(int* pointerParam, int& refParam);

int main()
{
    int num1 = 0;
    int num2 = 0;
    int* dynamicArray = nullptr;

    int* ptrToInt = &num1;
    *ptrToInt = 10;

    int& refToInt = num2;
    refToInt = 20;

    int* ptrToDynamicInt = new int;
    *ptrToDynamicInt = 30;

    /*
    Key differences:
    - Pointers can be reassigned, references cannot
    - Pointers can be nullptr, references must always refer to valid objects
    - Pointers use -> operator, references use . operator
    - Pointer syntax uses *, reference syntax uses &
    */

    dynamicArray = new int[5];
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 1;
    }
    delete[] dynamicArray;

    modifyValues(ptrToInt, refToInt);

    delete ptrToDynamicInt;

    cout << "=== Program Output ===" << endl;
    cout << "num1: " << num1 << endl;                   
    cout << "num2: " << num2 << endl;
    cout << "Dynamic value before deletion: 30" << endl;


    /*
    1. After calling modifyValues:
       - *ptrToInt becomes 11 (original num1 modified through pointer)
       - refToInt becomes 21 (original num2 modified through reference)

    2. Before deletion: *ptrToDynamicInt was 30
       After deletion: Accessing *ptrToDynamicInt becomes undefined behavior
       (program might crash or show garbage value)

    3. The first element of dynamicArray was 1 before deletion
       (array was initialized with values 1-5)
    */

    return 0;
}

void modifyValues(int* pointerParam, int& refParam) {
    (*pointerParam)++;  
    refParam++;         
}