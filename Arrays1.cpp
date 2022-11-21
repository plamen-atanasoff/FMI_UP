#include <iostream>
using namespace std;

// reverse values of a and b

void reverseValues(int& a, int& b)
{
    // a = 5, b = 8
    a = b - a;
    // a = 3, b = 8
    b = b - a;
    // a = 3, b = 5
    a = a + b;
    //a = 8, b = 5
}

int main()
{
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    reverseValues(a, b);
    cout << "\na = " << a << ", b = " << b;
}
