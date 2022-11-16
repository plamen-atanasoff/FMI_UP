#include <iostream>
using namespace std;

// print half full square with a given size

void printRow(int size, int fullColumns)
{
    for (int i = 1; i <= size; i++)
    {
        if (i <= fullColumns)
            cout << "*" << " ";
        else if (i == size)
            cout << "*" << " ";
        else
            cout << " " << " ";
    }

}

void printHalfFullSquare(int size)
{
    for (int row = 1; row <= size; row++)
    {
        if (row == 1 || row == size)
            printRow(size, size);
        else
            printRow(size, row - 1);

        cout << "\n";
    }
}

int main()
{
    unsigned int size;
    cin >> size;

    printHalfFullSquare(size);
}
