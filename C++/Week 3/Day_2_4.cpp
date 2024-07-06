#include <iostream>
using namespace std;

void func(int a)
{
    cout << "\n I am first func() " << a << endl;
}

template <class T>
void func(T a)
{
    cout << "\n I am templatised func() " << a << endl;
}


template <class T>
class OM
{
public:
    T data;
    OM(T a)
    {
        data = a;
    }
    void display();
};

template <class T>
void OM<T>::display()
{
    cout << data;
}

int main()
{
    OM<float> h(5.7);
    cout << h.data << endl;
    h.display();
    func(4.52); // Exact match takes the highest priority
    return 0;
}
