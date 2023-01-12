#include <iostream>
using namespace std;

void createMatrix(int** matrix, unsigned int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        unsigned int size;
        cin >> size;
        matrix[i] = new int[size + 1];
        matrix[i][0] = size;
    }
}

void fillMatrix(int** matrix, unsigned int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        int size = matrix[i][0];
        for (int j = 1; j <= size; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, unsigned int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        int size = matrix[i][0];
        for (int j = 1; j <= size; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

void clearMemory(int** matrix, unsigned int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
}

void sortMatrix(int** matrix, unsigned int rows)
{
    for (int i = 0; i < rows - 1; ++i)
    {
        int* shorterArr = matrix[i];
        int shorterArrIndex = 0;
        for (int j = i + 1; j < rows; ++j)
        {
            int* currentArr = matrix[j];
            //arr[0] contains the size
            if (currentArr[0] < shorterArr[0])
            {
                shorterArr = currentArr;
                shorterArrIndex = j;
            }
        }
        if (shorterArr != matrix[i])
        {
            matrix[shorterArrIndex] = matrix[i];
            matrix[i] = shorterArr;
        }
    }
}

int main()
{
    unsigned int rows;
    cin >> rows;

    int** matrix = new int*[rows];
    createMatrix(matrix, rows);
    fillMatrix(matrix, rows);
    printMatrix(matrix, rows);

    sortMatrix(matrix, rows);
    printMatrix(matrix, rows);

    clearMemory(matrix, rows);
    delete[] matrix;
}
