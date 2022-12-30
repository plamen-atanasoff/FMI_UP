#include <iostream>
using namespace std;

const unsigned int MAX_SIZE = 100;

unsigned int getWordsCount(const char* input)
{
    unsigned int count = 1;
    for (; *input != '\0'; ++input)
    {
        if (*input == ' ')
            count++;
    }
    return count;
}

bool isWord(const char* string)
{
    while (*string != ' ' && *string != '\0')
    {
        if ((*string < 'a' || *string > 'z') && (*string < 'A' || *string > 'Z'))
            return false;
        string++;
    }
    return true;
}

void getIndicesOfEveryWord(int* indices, const char* input, unsigned int wordsCount)
{
    for (int i = 0, j = 0; i < wordsCount; ++j)
    {
        if (isWord(input + j))
        {
            indices[i] = j;
            i++;
        }
        while (input[j] != ' ' && i < wordsCount)
        {
            j++;
        }
    }
}

void printAcronim(const int* indices, const char* input, unsigned int wordsCount)
{
    for (int i = 0; i < wordsCount; ++i)
    {
        cout << (char)(input[indices[i]] - 'a' + 'A');
    }
}

int main()
{
    char input[MAX_SIZE];
    cin.getline(input, MAX_SIZE);

    unsigned int wordsCount = getWordsCount(input);
    int* indicesArr = new int[wordsCount];
    getIndicesOfEveryWord(indicesArr, input, wordsCount);

    for (int i = 0; i < wordsCount; ++i)
    {
        cout << indicesArr[i] << ' ';
    }

    printAcronim(indicesArr, input, wordsCount);
}
