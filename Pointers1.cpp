#include <iostream>
using namespace std;

//return a pointer to the smallest element of an array

const int* getPointerToTheSmallestNum(const int* arr, int size)
{
    int smallestNumIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (*(arr + i) < *(arr + smallestNumIndex))
            smallestNumIndex = i;
    }

    return arr + smallestNumIndex;
}

int main()
{
    int size = 5;
    int arr[] = { 4, 7, 1, -5, 10 };
    const int* pointer = getPointerToTheSmallestNum(arr, size);
    cout << pointer << " " << *pointer;

    //cout << arr << endl;
    //cout << *(arr + 1) << endl;
}
