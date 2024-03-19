#include <iostream>
using namespace std;

const unsigned int MAX_SIZE = 1024;
const unsigned int MAX_LENGTH = 50;
char arr[MAX_SIZE][MAX_LENGTH];
// index is counter for word
int histogram[MAX_SIZE];
// index is word 
char words[MAX_SIZE][MAX_LENGTH];

void validateInput(unsigned int& n)
{
    do
    {
        cin >> n;
    } while (n >= MAX_SIZE);
}

void fillArray(char arr[][MAX_LENGTH], unsigned int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

bool wordExists(const char* word, char words[][MAX_LENGTH])
{
    for (int i = 0; words[i][0] != '\0'; ++i)
    {
        bool exists = true;
        for (int j = 0; word[j] != '\0'; ++j)
        {
            if (word[j] != words[i][j])
            {
                exists = false;
                break;
            }
        }
        if (exists)
        {
            return true;
        }
    }
    return false;
}

int getPosition(const char words[][MAX_LENGTH])
{
    int i = 0;
    while (words[i][0] != '\0')
    {
        ++i;
    }
    return i;
}

int getPosition(const char* word, const char words[][MAX_LENGTH])
{
    int i = 0;
    while (words[i][0] != '\0')
    {
        bool found = true;
        for (int j = 0; word[j] != '\0'; ++j)
        {
            if (word[j] != words[i][j])
            {
                found = false;
                break;
            }
        }
        if (found)
            return i;

        ++i;
    }
}

void fillWord(const char* word, char words[][MAX_LENGTH], int position)
{
    for (int i = 0; word[i] != '\0'; ++i)
    {
        words[position][i] = word[i];
    }
    //words[position][i] = '\0';
}

void fillHistogram(char arr[][MAX_LENGTH], unsigned int size, char words[][MAX_LENGTH], int* histogram)
{
    for (int i = 0; i < size; ++i)
    {
        if (wordExists(arr[i], words))
        {
            int position = getPosition(arr[i], words);
            histogram[position]++;
        }
        else
        {
            int freePosition = getPosition(words);
            fillWord(arr[i], words, freePosition);
            histogram[freePosition]++;
        }
    }
}

void printResult(const char words[][MAX_LENGTH], const int* histogram)
{
    for (int i = 0; words[i][0] != '\0'; ++i, ++histogram)
    {
        cout << *histogram << " - " << words[i] << "\n";
    }
}

int main()
{
    unsigned int n;
    validateInput(n);
    fillArray(arr, n);

    fillHistogram(arr, n, words, histogram);

    printResult(words, histogram);
}
