#include <iostream>
using namespace std;

const unsigned int MAX_SIZE = 100;

bool isLetter(char el)
{
    return el >= 'a' && el <= 'z';
}

void capitalizeLetter(char* letter)
{
    *letter = *letter - 'a' + 'A';
}

void shiftLeft(char* arr)
{
    while (*arr != '\0')
    {
        *arr = *(arr + 1);
        arr++;
    }
}

void capitalizeWordsInBrackets(char* arr)
{
    while (*arr != '\0')
    {
        if (*arr == '[')
        {
            shiftLeft(arr);
            while (*arr != ']')
            {
                if (isLetter(*arr))
                    capitalizeLetter(arr);
                arr++;
            }
            shiftLeft(arr);
        }
        arr++;
    }
}

int main()
{
    char arr[MAX_SIZE];
    cin.getline(arr, MAX_SIZE);

    capitalizeWordsInBrackets(arr);

    cout << arr;
}