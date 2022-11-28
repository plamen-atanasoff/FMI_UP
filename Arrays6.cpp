#include <iostream>
using namespace std;

// print numbers from an array whose index + the number equals another number from the array 

unsigned int validateSize()
{
    unsigned int size;
    do
    {
        cin >> size;
    } while (size < 1 || size > 100);

    return size;
}

void fillArray(int arr[], unsigned int& size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

void printSpecialNums(const int arr[], unsigned int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (i + arr[i] == arr[j])
                cout << arr[i] << endl;
        }
    }
}

int main()
{
    unsigned int size = validateSize();

    int array[100];
    fillArray(array, size);

    printSpecialNums(array, size);
}
