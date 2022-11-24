#include <iostream>
using namespace std;

unsigned int getIndexOfMinNum(const double arr[], unsigned int size)
{
    unsigned int minIndex = 0;
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[minIndex] > arr[i])
            minIndex = i;
    }

    return minIndex;
}

unsigned int getIndexOfMaxNum(const double arr[], unsigned int size)
{
    unsigned int maxIndex = 0;
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[maxIndex] < arr[i])
            maxIndex = i;
    }

    return maxIndex;
}

double getSumOfElements(const double arr[], unsigned int size)
{
    double sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}
double getAverageOfElements(const double arr[], unsigned int size)
{
    return getSumOfElements(arr, size) / size;
}

void validateSize(unsigned int& size)
{
    do
    {
        cin >> size;
    } while (size <= 1 || size > 100);
}

void fillArray(double arr[], unsigned int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

int main()
{
    unsigned int size;
    validateSize(size);

    double array[100];
    fillArray(array, size);

    cout << "Index of min number: " << getIndexOfMinNum(array, size) << endl;
    cout << "Index of max number: " << getIndexOfMaxNum(array, size) << endl;
    cout << "Sum of elements: " << getSumOfElements(array, size) << endl;
    cout << "Average of elements: " << getAverageOfElements(array, size) << endl;
}
