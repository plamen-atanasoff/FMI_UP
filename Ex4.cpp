#include <iostream>
#include <cstring>
using namespace std;

const unsigned int MAX_SIZE = 100;

void concatStr(char* newStr, char* arr1, char* arr2, size_t size)
{
    char* currentArr = arr1;
    for (int i = 0, j = 0; i < size; ++i, ++j)
    {
        if (currentArr[j] == '\0')
        {
            currentArr = arr2;
            j = 0;
        }
        newStr[i] = currentArr[j];
    }
    newStr[size - 1] = '\0';
}

int main()
{
    char arr1[MAX_SIZE];
    char arr2[MAX_SIZE];

    cin.getline(arr1, MAX_SIZE);
    cin.getline(arr2, MAX_SIZE);

    size_t size = strlen(arr1) + strlen(arr2);
    char* newStr = new char[size + 1];
    concatStr(newStr, arr1, arr2, size);

    cout << newStr;
    delete[] newStr;
}
