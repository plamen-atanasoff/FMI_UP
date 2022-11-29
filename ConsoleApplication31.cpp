#include <iostream>
using namespace std;

void insert(int arr[], int size, int el)
{
    for (int i = size - 1; i > 0; --i)
    {
        if (el >= arr[i])
        {
            arr[i + 1] = el;
            return;
        }
        else
            arr[i + 1] = arr[i];
    }
}

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

void printArray(const int* arr, int size)
{
    for (int i = 0; i < size + 1; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int numToInsert;
    cin >> numToInsert;

    //size must be <= 10
    int size;
    cin >> size;

    int arr[11];
    fillArray(arr, size);

    insert(arr, size, numToInsert);

    printArray(arr, size);
}
