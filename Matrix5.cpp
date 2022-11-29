#include <iostream>
using namespace std;

void transposeMatrix(int matrix[][10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void multiplyMatrix(int matrix[][10], int n, int m, int num)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] *= num;
        }
    }
}

void fillMatrix(int matrix[][10], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][10], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int num;
    cin >> num;

    int matrix[10][10];
    fillMatrix(matrix, n, m);
    //multiplyMatrix(matrix, n, m, num);
    //printMatrix(matrix, n, m);

    // transpose only n x n matrices
    transposeMatrix(matrix, n);
    printMatrix(matrix, n, n);
}
