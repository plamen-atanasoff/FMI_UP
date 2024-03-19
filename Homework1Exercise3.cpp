#include <iostream>
using namespace std;

const int MAX_SIZE = 9;

void validateSize(int& fieldSize)
{
    do
    {
        cout << "Enter size of field: ";
        cin >> fieldSize;
        cout << "\n";
    } while (fieldSize < 3 || fieldSize > 9);
}

void printField(const char field[][MAX_SIZE], int fieldSize)
{
    for (int i = 0; i < fieldSize; ++i)
    {
        for (int j = 0; j < fieldSize; ++j)
        {
            cout << "[ " << field[i][j] << " ]" << " ";
        }
        cout << "\n";
        cout << "\n";
    }
    cout << "\n";
}

void fillField(char field[][MAX_SIZE], int fieldSize)
{
    for (int i = 0; i < fieldSize; ++i)
    {
        for (int j = 0; j < fieldSize; ++j)
        {
            field[i][j] = ' ';
        }
    }
}

char chooseMark()
{
    char mark;
    do
    {
        cout << "Choose X or O" << endl;
        cin >> mark;
        cout << "\n";
    } while (mark != 'X' && mark != 'O');

    return mark;
}

bool isValidInput(unsigned short x, unsigned short y, int fieldSize)
{
    return (x >= 0 && x <= fieldSize) && (y >= 0 && y <= fieldSize);
}

bool isCellFree(const char board[][MAX_SIZE], unsigned short x, unsigned short y)
{
    return board[x][y] == ' ';
}

void inputCoordinates(char field[][MAX_SIZE], unsigned short& x, unsigned short& y, int fieldSize)
{
    do
    {
        cout << "Enter cell row: ";
        cin >> x;
        x -= 1;
        cout << "Enter cell column: ";
        cin >> y;
        y -= 1;
        cout << "\n";
    } while (!isValidInput(x, y, fieldSize) || !isCellFree(field, x, y));
}

bool checkIfRowContainsSameMarks(const char board[][MAX_SIZE], char mark, unsigned short markRow, int fieldSize)
{
    for (int i = 0; i < fieldSize; ++i)
    {
        if (board[markRow][i] != mark)
            return false;
    }
    return true;
}

bool checkIfColContainsSameMarks(const char board[][MAX_SIZE], char mark, unsigned short markCol, int fieldSize)
{
    for (int i = 0; i < fieldSize; ++i)
    {
        if (board[i][markCol] != mark)
            return false;
    }
    return true;
}

bool rowOrColFilledWithMark(const char board[][MAX_SIZE], char mark, unsigned short markRow, unsigned short markCol, int fieldSize)
{
    return checkIfRowContainsSameMarks(board, mark, markRow, fieldSize) ||
        checkIfColContainsSameMarks(board, mark, markCol, fieldSize);
}

bool isInMainDiagonal(unsigned short markRow, unsigned short markCol)
{
    return markRow == markCol;
}

bool isInSecondaryDiagonal(unsigned short markRow, unsigned short markCol, int fieldSize)
{
    return markRow + markCol == fieldSize - 1;
}

bool mainDiagonalContainsSameMarks(const char field[][MAX_SIZE], char mark, int fieldSize)
{
    for (int i = 0; i < fieldSize; ++i)
    {
        if (field[i][i] != mark)
            return false;
    }
    return true;
}

bool secondaryDiagonalContainsSameMarks(const char field[][MAX_SIZE], char mark, int fieldSize)
{
    for (int i = 0, j = 2; i < fieldSize; ++i, --j)
    {
        if (field[i][j] != mark)
            return false;
    }
    return true;
}

bool diagonalsFilledWithMark(const char field[][MAX_SIZE], char mark, unsigned short markRow, unsigned short markCol, int fieldSize)
{
    return (isInMainDiagonal(markRow, markCol) && mainDiagonalContainsSameMarks(field, mark, fieldSize)) ||
        (isInSecondaryDiagonal(markRow, markCol, fieldSize) && secondaryDiagonalContainsSameMarks(field, mark, fieldSize));
}

bool isWinner(const char field[][MAX_SIZE], char mark, unsigned short markRow, unsigned short markCol, int fieldSize)
{
    return rowOrColFilledWithMark(field, mark, markRow, markCol, fieldSize) || diagonalsFilledWithMark(field, mark, markRow, markCol, fieldSize);
}

bool isDraw(const char field[][MAX_SIZE], int fieldSize)
{
    for (int i = 0; i < fieldSize; ++i)
    {
        for (int j = 0; j < fieldSize; ++j)
        {
            if (field[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    int fieldSize;
    validateSize(fieldSize);

    char field[MAX_SIZE][MAX_SIZE];
    fillField(field, fieldSize);

    bool isFirstPlayerTurn = true;
    unsigned short x, y;
    char firstPlayerMark = chooseMark();
    char secondPlayerMark = firstPlayerMark == 'X' ? 'O' : 'X';

    while (true)
    {
        cout << "It's " << (isFirstPlayerTurn ? "first" : "second") << " player's turn!" << endl;
        cout << "\n";

        inputCoordinates(field, x, y, fieldSize);

        field[x][y] = isFirstPlayerTurn ? firstPlayerMark : secondPlayerMark;
        printField(field, fieldSize);

        if (isWinner(field, field[x][y], x, y, fieldSize))
        {
            cout << (isFirstPlayerTurn ? "First" : "Second") << " player won!";
            break;
        }
        else if (isDraw(field, fieldSize))
        {
            cout << "It's a draw!";
            break;
        }

        isFirstPlayerTurn = !isFirstPlayerTurn;
    }
}
