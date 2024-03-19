#include <iostream>
using namespace std;

void printPermutationsRec(int pos, const char* arr, char* perm, int size)
{
    if (pos == size)
    {
        perm[pos] = '\0';
        cout << perm << '\n';
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        perm[pos] = arr[i];
        printPermutationsRec(pos + 1, arr, perm, size);
    }
}

void printPermutations(const char* arr, unsigned int size)
{
    char* perm = new char[size + 1];

    printPermutationsRec(0, arr, perm, size);
    delete[] perm;
}

int main()
{
    char arr[] = { 'f', 'm', 'i', 'o', 'k', '\0' };
    unsigned int size = 5;

    printPermutations(arr, size);
}
