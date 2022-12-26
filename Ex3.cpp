#include <iostream>
using namespace std;

const unsigned int MAX_SIZE = 100;

bool isDigit(char el)
{
    return el >= '0' && el <= '9';
}

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

void manipulateString(char* arr)
{
    bool capitalizeLetters = false;
    int digit = 0;
    while (*arr != '\0')
    {
        if (isDigit(*arr))
        {
            capitalizeLetters = true;
            digit = int(*arr - '0');
            shiftLeft(arr);

            for (int i = 1; i <= digit && *arr != '\0'; ++i, ++arr)
            {
                if (isLetter(*arr))
                    capitalizeLetter(arr);
            }
        }
        if (*arr == '\0')
            return;
        if (capitalizeLetters)
        {
            capitalizeLetters = false;
            continue;
        }
        arr++;
    }
}

int main()
{
    char arr[MAX_SIZE];
    cin.getline(arr, MAX_SIZE);

    manipulateString(arr);

    cout << arr;
}
