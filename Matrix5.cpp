#include <iostream>
using namespace std;

const unsigned MAX_ROWS = 10;
const unsigned MAX_COLUMNS = 10;


void transposeMatrix(int matrix[][MAX_COLUMNS], unsigned& n, unsigned& m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < m; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    int temp = n;
    n = m;
    m = temp;
}

void multiplyMatrix(int matrix[][MAX_COLUMNS], unsigned n, unsigned m, int num)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] *= num;
        }
    }
}

void fillMatrix(int matrix[][MAX_COLUMNS], unsigned n, unsigned m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][MAX_COLUMNS], unsigned n, unsigned m)
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
    // matrix can't be bigger than 10 x 10
    unsigned n, m;
    cin >> n >> m;

    int num;
    cin >> num;

    int matrix[MAX_ROWS][MAX_COLUMNS];
    fillMatrix(matrix, n, m);

    //multiplyMatrix(matrix, n, m, num);
    //printMatrix(matrix, n, m);

    //transposeMatrix(matrix, n, m);
    //printMatrix(matrix, n, m);
}
