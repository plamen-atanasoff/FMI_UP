#include <iostream>
using namespace std;

// sort positive int num by its digits ascending

int countDigitInNum(int num, int digitToCount)
{
    int counter = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        if (lastDigit == digitToCount)
            ++counter;
        num /= 10;
    }

    return counter;
}

int sortNum(unsigned int num)
{
    int sortedNum = 0;
    for (int digit = 1; digit <= 9; ++digit)
    {
        int digitCount = countDigitInNum(num, digit);
        for (int i = 1; i <= digitCount; ++i)
        {
            sortedNum += digit;
            sortedNum *= 10;
        }
    }

    return sortedNum / 10;
}

int main()
{
    unsigned int num;
    cin >> num;

    cout << "Sorted num: " << sortNum(num) << endl;
}