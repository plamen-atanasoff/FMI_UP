#include <iostream>
using namespace std;

// find if all digits of a positive integer are equal

int countNumber(int num, int numToCount)
{
	int counter = 0;
	while (num > 0)
	{
		int lastDigit = num % 10;
		if (lastDigit == numToCount)
			counter++;
		num /= 10;
	}
	return counter;
}

int findBiggestNumber(int num)
{
	int biggestNum = 0;
	while (num > 0)
	{
		int lastDigit = num % 10;
		if (lastDigit > biggestNum)
		{
			biggestNum = lastDigit;
		}
		num /= 10;
	}
	return biggestNum;
}

int main()
{
	int num;
	cout << "Number: ";
	cin >> num;
	
	int lastDigit = num % 10;
	bool allDigitsAreEqual = true;
	while (num > 0)
	{
		int currentDigit = num % 10;
		if (currentDigit != lastDigit)
		{
			allDigitsAreEqual = false;
			break;
		}
		num /= 10;
	}

	cout << (allDigitsAreEqual ? "yes" : "no");
}
