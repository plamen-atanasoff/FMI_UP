#include <iostream>
using namespace std;

//create and print special matrix

void printMatrix(int* firstEl, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << *(firstEl + (i * size) + j) << " ";
        }
        cout << "\n";
    }
}

void createMatrix(int* firstEl, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == j)
                *(firstEl + (i * size) + j) = i + 1;
            else if (i < j)
                *(firstEl + (i * size) + j) = j - i;
            else
                *(firstEl + (i * size) + j) = (i + 1) * (j + 1);
        }
    }
}

void validateSize(int& size)
{
    do
    {
        cin >> size;
    } while (size < 1 || size > 20);
}

int main()
{
    int matrix[20][20];
    int size;
    validateSize(size);

    int* firstElPtr = &matrix[0][0];

    createMatrix(firstElPtr, size);
    printMatrix(firstElPtr, size);
}
