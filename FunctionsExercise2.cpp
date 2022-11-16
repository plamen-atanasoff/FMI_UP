#include <iostream>
using namespace std;

// print all 4 digit numbers with even digits

bool checkDigitsEven(int num, int lengthOfNum)
{
    for (int i = 1; i <= lengthOfNum; i++)
    {
        int currentDigit = num % 10;
        if (currentDigit % 2 != 0)
        {
            return false;
        }

        num /= 10;
    }

    return true;
}

int main()
{
    const int lengthOfNum = 4;
    for (int i = 2000; i <= 8888; i += 2)
    {
        bool allDigitsAreEven = checkDigitsEven(i, lengthOfNum);
        if (allDigitsAreEven)
            cout << i << endl;
    }
}
