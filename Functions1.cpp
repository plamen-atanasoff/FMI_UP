#include <iostream>
using namespace std;

// find biggest of three numbers

int biggestNum(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int main()
{
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    cout << biggestNum(biggestNum(num1, num2), num3);
}
