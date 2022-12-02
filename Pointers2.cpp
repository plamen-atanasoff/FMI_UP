#include <iostream>
using namespace std;

int* getPointerToEl(int* firstEl, int* lastEl, int numToFind)
{
    int i = 0;
    do
    {
        if (*(firstEl + i) == numToFind)
            return firstEl + i;
        ++i;
    } while (firstEl + i != lastEl);

    return nullptr;
}

int main()
{
    int arr[] = { 1, 2, 3, 6, 7, 6 };
    int size = 6;

    int* arrPointerFirstEl = &arr[0];
    int* arrPointerLastEl = &arr[size - 1];

    int* elementPointer = getPointerToEl(arrPointerFirstEl, arrPointerLastEl, 10);

    //check if pointers has correct value
    cout << arr + 3 << " " << arr[3] << endl;

    if (elementPointer == nullptr)
        cout << "nullptr" << endl;
    else
        cout << elementPointer << " " << *elementPointer << endl;
}
