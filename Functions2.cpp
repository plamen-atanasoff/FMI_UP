#include <iostream>
using namespace std;

// turn lowercase letter into uppercase

char makeUppercase(char letter)
{
    int asciiCodeUpper = int(letter) - 32;
    return char(asciiCodeUpper);
}

int main()
{
    char letter;
    cin >> letter;

    cout << makeUppercase(letter);
}
