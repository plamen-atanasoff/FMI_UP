#include <iostream>
using namespace std;

// make pow function for int and double

int myPow(int num, unsigned int power)
{
    if (power == 0)
        return 1;

    int result = num;
    for (int i = 1; i < power; i++)
    {
        result *= num;
    }

    return result;
}

double myPow(double num, unsigned int power)
{
    if (power == 0)
        return 1;

    double result = num;
    for (int i = 1; i < power; i++)
    {
        result *= num;
    }

    return result;
}

int main()
{
    double num;
    int power;
    cout << "Enter number: ";
    cin >> num;
    cout << endl << "Enter power: ";
    cin >> power;

    cout << myPow(num, power);
}
