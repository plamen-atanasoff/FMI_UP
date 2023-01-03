#include <iostream>
using namespace std;

int getUniqueNum(const int* arr, size_t size)
{
    int uniqueNum = 0;
    for (int i = 0; i < size; ++i)
    {
        uniqueNum ^= arr[i];
    }

    return uniqueNum;
}

unsigned int countOnes(int num)
{
    unsigned int counter = 0;
    while (num != 0)
    {
        if (num & 1)
            counter++;
        num >>= 1;
    }

    return counter;
}

int main()
{
    int arr[] = { 9, 9, 9, -50, 12, 15, 15, 12, -50 };
    int size = sizeof arr / sizeof arr[0];
    //cout << getUniqueNum(arr, size);
    cout << countOnes(189);
}
