#include <iostream>
using namespace std;

// print all prime nums using Sieve of Eratosthenes between 1 and MAX_NUM

void fillAllMultiplesByNum(bool arr[], unsigned int upperLimit, size_t num)
{
    for (size_t i = num + num; i < upperLimit; i += num)
    {
        arr[i] = false;
    }
}

void getPrimesUsingEratosthenes(bool arr[], const unsigned int upperLimit)
{
    for (size_t i = 2; i < upperLimit; ++i)
    {
        if (arr[i])
            fillAllMultiplesByNum(arr, upperLimit, i);
    }
}

void printPrimes(bool arr[], const unsigned int upperLimit)
{
    for (size_t i = 2; i < upperLimit; ++i)
    {
        if (arr[i])
            cout << i << " ";
    }
}

void fillArray(bool arr[], const unsigned int upperLimit, bool element)
{
    for (size_t i = 2; i < upperLimit; ++i)
    {
        arr[i] = element;
    }
}

int main()
{
    const unsigned int MAX_NUM = 100;
    bool array[100];

    fillArray(array, MAX_NUM, true);
    getPrimesUsingEratosthenes(array, MAX_NUM);
    printPrimes(array, MAX_NUM);
}
