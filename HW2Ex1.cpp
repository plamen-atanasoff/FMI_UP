#include <iostream>
#include <iomanip>
using namespace std;

void print(const double* grades, unsigned int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << fixed << setprecision(2) << grades[i] << ' ';
    }
    cout << '\n';
}

int fibRec(int n, int* cache)
{
    if (cache[n] != 0)
        return cache[n];
    if (n == 0 || n == 1)
        return 1;

    cache[n] = fibRec(n - 1, cache) + fibRec(n - 2, cache);
    return cache[n];
}

int fibNextElPosRec(int current, int previous, int pos, int el)
{
    if (current == el)
        return pos;

    return fibNextElPosRec(current + previous, current, pos + 1, el);
}

int fib(int el)
{
    int size = fibNextElPosRec(1, 1, 2, el);
    int* cache = new int[size + 1];
    for (int i = 0; i <= size; ++i)
    {
        cache[i] = 0;
    }
    int res = fibRec(size, cache);
    delete[] cache;
    return res;
}

void addMoreCapacity(double*& grades, unsigned int& capacity)
{
    int oldSize = capacity;
    capacity = fib(capacity);
    double* newGrades = new double[capacity];
    for (int i = 0; i < oldSize; ++i)
    {
        newGrades[i] = grades[i];
    }
    delete[] grades;
    grades = newGrades;
}

bool gradeIsValid(double grade)
{
    return grade >= 2.00 && grade <= 6.00;
}

double* getGrades(unsigned int& size, unsigned int& capacity)
{
    double* grades = new double[capacity];
    double input;
    int i = 0;
    while (true)
    {
        cin >> input;
        if (input == 0)
            break;

        if (!gradeIsValid(input))
            continue;

        size++;
        if (size == capacity)
            addMoreCapacity(grades, capacity);

        grades[i++] = input;
    }

    return grades;
}

int main()
{
    unsigned int size = 0, capacity = 2;
    double* grades = getGrades(size, capacity);

    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;

    if (size > 0)
    {
        cout << "Grades: ";
        print(grades, size);
    }
    else
        cout << "Array is empty!";

    delete[] grades;
}
