#include <iostream>
#include <memory>

using namespace std;

int g = 10;

template<typename T>
struct smart_ptr {
    smart_ptr() = default;
    smart_ptr(T* p) : p(p) {}
    ~smart_ptr() {
        delete p;
        cout << "Deleted" << endl;
    }
    T* p = nullptr;

    T& operator * () { return *p; }
    T* operator & () { return p; }
};
 
int main()
{
    g = 23;
    int i = 5;
        int* p = &i;
    {
        smart_ptr<int> sptr{ new int(21) };
        cout << "Value: " << *sptr << endl;
        cout << "Value: " << &sptr << endl;
        cout << "Value: " << sptr.p << endl;
    }

    {
        smart_ptr<float> sptr2{ new float(25.5f) };
    }

    unique_ptr<int> uptr = make_unique<int>(23);
    cout << "Value: " << *uptr << endl;
    unique_ptr<int> uptr2 = make_unique<int>(25);
    shared_ptr<int> sharedptr = make_shared<int>(29);
    cout << "Value: " << sharedptr.use_count() << endl;
    shared_ptr<int> sharedptr2 = sharedptr;
    cout << "Value: " << sharedptr.use_count() << endl;
    shared_ptr<int> sharedptr3 = sharedptr2;
    cout << "Value: " << sharedptr.use_count() << endl;
};