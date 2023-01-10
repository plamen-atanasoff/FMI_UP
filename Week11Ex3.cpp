#include <iostream>
using std::cout;
using std::endl;

size_t toBinaryRecTail(size_t number, size_t res, int multiplier) {
	if (number == 1)
		return res;
	return toBinaryRecTail(number / 2, (number % 2) * multiplier + res, multiplier * 10);
}

size_t toBinary(int n)
{
	int temp = n;
	int result = 1;
	while (temp != 0)
	{
		temp /= 2;
		result *= 10;
	}
	return toBinaryRecTail(n, result / 10, 1);
}

int main()
{
	int n = 100;
	cout << n << ", to binary:  " << toBinary(n) << endl;
}