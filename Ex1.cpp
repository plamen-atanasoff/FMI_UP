#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

bool isValid(char el)
{
    if (el == ' ')
        return false;
    if (el >= 'A' && el <= 'Z')
        return false;
    if (el >= 'a' && el <= 'z')
        return false;

    return true;
}

char* getLongestSubsequence(char* input)
{
    int i = 0;
    int biggestCount = 0;
    int currentCount = 0;
    char* longestPtr = input;

    while (*(input + i) != '\0')
    {
        if (!isValid(*(input + i)))
        {
            if (currentCount > biggestCount)
            {
                biggestCount = currentCount;
                longestPtr = input + i;
                longestPtr -= currentCount;

            }
            currentCount = 0;
        }
        else
            currentCount++;
        i++;
    }

    return longestPtr;
}

void printArr(const char* arr)
{
    int i = 0;
    while (*(arr + i) != '\0' && isValid(*(arr + i)))
    {
        cout << *(arr + i);
        i++;
    }
}

int main()
{
    char arr[MAX_SIZE];
    cin.getline(arr, MAX_SIZE);

    printArr(getLongestSubsequence(arr));
}
