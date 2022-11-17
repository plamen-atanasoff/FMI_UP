#include <iostream>
using namespace std;

// remove digit from number by given position

int reverseNum(int num)
{
    int reversedNum = 0;
    for (int i = 1; num > 0; num /= 10)
    {
        int lastDigit = num % 10;
        reversedNum += lastDigit;
        reversedNum *= 10;
    }

    return reversedNum /= 10;
}

int removeDigit(int num, int position)
{
    int newNum = 0;

    for (int i = 1; num > 0; i++)
    {
        if (i == position)
        {
            num /= 10;
            continue;
        }
        int lastDigit = num % 10;
        newNum += lastDigit;
        newNum *= 10;
        num /= 10;
    }

    return reverseNum(newNum);
}

int main()
{
    int num, position;
    cin >> num >> position;

    cout << removeDigit(num, position);
}
