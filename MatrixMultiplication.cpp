#include <iostream>
using namespace std;

const unsigned int M_1_ROWS = 2;
const unsigned int M_1_COLS = 3;
const unsigned int M_2_COLS = 4;

void fillMatrix(double matrix[][M_1_COLS])
{
    for (int i = 0; i < M_1_ROWS; ++i)
    {
        for (int j = 0; j < M_1_COLS; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(double matrix[][M_2_COLS])
{
    for (int i = 0; i < M_1_COLS; ++i)
    {
        for (int j = 0; j < M_2_COLS; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

double getElement(const double m1[][M_1_COLS], const double m2[][M_2_COLS], int row, int col)
{
    double sum = 0;
    for (int i = 0; i < M_1_COLS; ++i)
    {
        sum += m1[row][i] * m2[i][col];
    }

    return sum;
}

void multiplyMatrices(double newMatrix[][M_2_COLS], const double m1[][M_1_COLS], const double m2[][M_2_COLS])
{
    for (int i = 0; i < M_1_ROWS; ++i)
    {
        for (int j = 0; j < M_2_COLS; ++j)
        {
            newMatrix[i][j] = getElement(m1, m2, i, j);
        }
    }
}

void printMatrix(const double matrix[][M_2_COLS])
{
    for (int i = 0; i < M_1_ROWS; ++i)
    {
        for (int j = 0; j < M_2_COLS; ++j)
        {
            cout << "[ " << matrix[i][j] << " ]";
        }
        cout << '\n';
    }
}

int main()
{
    double matrix1[M_1_ROWS][M_1_COLS];
    double matrix2[M_1_COLS][M_2_COLS];

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    double newMatrix[M_1_ROWS][M_2_COLS];
    multiplyMatrices(newMatrix, matrix1, matrix2);
    printMatrix(newMatrix);
}
