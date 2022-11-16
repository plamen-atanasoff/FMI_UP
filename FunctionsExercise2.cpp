#include <iostream>
using namespace std;

// print all positive integers in an interval between a and b

void validateInput(unsigned int& a, unsigned int& b)
{
	do
	{
		cout << "a = ";
		cin >> a;
		cout << "\n" << "b = ";
		cin >> b;
	} while (a > b);
}

void printAllIntegersInAnInterval(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		cout << i << " ";
	}
}

int main()
{
	unsigned int a, b;
	validateInput(a, b);
	printAllIntegersInAnInterval(a, b);
}
