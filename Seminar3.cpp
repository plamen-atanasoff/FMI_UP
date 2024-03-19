#include <iostream>

using namespace std;

int main()
{
	//first exercise
	//int n;
	//cin >> n;
	//
	//int counter = 0;
	//
	//while (n > 0)
	//{
	//	int year;
	//	cin >> year;
	//
	//	if (year % 4 == 0 && (year % 100 == 0) == (year % 400 == 0))
	//	{
	//		counter++;
	//	}
	//	n--;
	//}
	//
	//cout << counter;

	//second exercise
	//unsigned int num1, num2;
	//cin >> num1 >> num2;
	//
	//while (num1 <= num2)
	//{
	//	//find if num1 is prime
	//	bool isPrime = true;
	//	for (int i = 2; i < num1; i++)
	//	{
	//		if (num1 % i == 0)
	//		{
	//			isPrime = false;
	//		}
	//	}
	//
	//	if (isPrime && num1 != 1)
	//	{
	//		cout << num1 << ' ';
	//	}
	//
	//	num1++;
	//}

	//third exercise
	//int a, b;
	//cin >> a >> b;
	//
	//while (a <= b)
	//{
	//	int currentNum = a;
	//
	//	int lastDigit = currentNum % 10;
	//	currentNum -= lastDigit;
	//	currentNum /= 10;
	//	int secondDigit = currentNum % 10;
	//	currentNum -= secondDigit;
	//	currentNum /= 10;
	//	int thirdDigit = currentNum % 10;
	//
	//	if (lastDigit != secondDigit && secondDigit != thirdDigit && lastDigit != thirdDigit )
	//		cout << a << '\n';
	//	if (secondDigit == 0 && thirdDigit == 0)
	//		cout << a << '\n';
	//
	//	a++;
	//}

	//exercise 4
	//int num;
	//cin >> num;
	//
	//int currentNum = num;
	//int palindrome = 0;
	//
	//while (currentNum != 0)
	//{
	//	int lastDigit = currentNum % 10;
	//	currentNum -= lastDigit;
	//	currentNum /= 10;
	//
	//	palindrome *= 10;
	//	palindrome += lastDigit;
	//}
	//
	//if (palindrome == num)
	//	cout << "palindrome";
	//else
	//	cout << "not palindrome";

	//exercise 5
	//int num;
	//cin >> num;
	//
	//int result = 0;
	//while (num != 0)
	//{
	//	result += num;
	//
	//	cin >> num;
	//}
	//
	//cout << result;

	//exercise 6
	//int numbers;
	//cin >> numbers;
	//
	//int newNum = 0;
	//for (int i = 1; i <= numbers; i++)
	//{
	//	int currentNum;
	//	cin >> currentNum;
	//
	//	if (currentNum % 2 == 0)
	//	{
	//		newNum *= 10;
	//		newNum += currentNum;
	//	}
	//}
	//
	//cout << newNum * 2;

	for (int k = 0; k < 10; k++) 
		cout << k;
	int k;
	do cin >> k; while (k < 1 || k > 10);
	while(k > 5) k = k - 5;
}

