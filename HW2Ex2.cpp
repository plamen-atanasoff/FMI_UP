#include <iostream>
using namespace std;

const unsigned int MAX_POSSIBLE_MOVES = 8;
const unsigned int ALL_POSSIBLE_MOVES[MAX_POSSIBLE_MOVES][2] = {{-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}};

void printMatrix(int** matrix, unsigned int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] < 10)
                cout << "[ " << matrix[i][j] << "] ";
            else
                cout << "[" << matrix[i][j] << "] ";
        }
        cout << '\n' << '\n';
    }
    cout << '\n';
}

void initMatrix(int** matrix, unsigned int n, int el)
{
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = el;
        }
    }
}

bool ManipulateMatrixRec(int** matrix, unsigned int size, int x, int y, int move)
{
    // x is current row, y is current col
    if (x < 0 || x >= size)
        return false;
    if (y < 0 || y >= size)
        return false;
    if (matrix[x][y] != -1)
        return false;

    matrix[x][y] = move;

    if (move == size * size - 1)
        return true;

    //printMatrix(matrix, size);
    for (int i = 0; i < MAX_POSSIBLE_MOVES; ++i)
    {
        bool isSolved = ManipulateMatrixRec(matrix, size, x + ALL_POSSIBLE_MOVES[i][0], y + ALL_POSSIBLE_MOVES[i][1], move + 1);
        if (isSolved)
            return true;
    }

    matrix[x][y] = -1;
    //printMatrix(matrix, size);
    return false;
}

bool getResult(int** matrix, unsigned int size)
{
    return ManipulateMatrixRec(matrix, size, 0, 0, 0);
}

void deleteMatrix(int** matrix, unsigned int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }
}

int main()
{
    unsigned int n;
    cin >> n;

    int** matrix = new int* [n];
    initMatrix(matrix, n, -1);

    bool solutionExists = getResult(matrix, n);
    if (solutionExists)
    {
        cout << '\n' << "There is a solution!" << '\n' << '\n';
        printMatrix(matrix, n);
    }
    else
        cout << "Solution does not exist!" << endl;

    deleteMatrix(matrix, n);
    delete[] matrix;
}
