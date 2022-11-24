#include <iostream>
#include <cmath>
using namespace std;

// multiply and print positive integer n by the biggest(but not bigger than n) prime num

bool isPrime(unsigned int num)
{
    for (size_t i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

unsigned int getBiggestPrime(unsigned int num)
{
    for (size_t i = num - 1; i >= 2; --i)
    {
        if (isPrime(i))
            return i;
    }
}

unsigned int multiplyByPrime(unsigned int num)
{
    if (num <= 1)
        return 666;
    return getBiggestPrime(num) * num;
}

int main()
{
    unsigned int num;
    cin >> num;

    cout << multiplyByPrime(num) << endl;
}
