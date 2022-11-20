#include <iostream>
using namespace std;

// Mcdonalds ordering until user doesn't have enough money to order

void validateInput(double& money, int& dayOfTheWeek)
{
    do
    {
        cout << "How much money do you have? " << endl;
        cin >> money;
    } while (money <= 0);

    do
    {
        cout << "Enter the day of the week: " << endl;
        cin >> dayOfTheWeek;
    } while (dayOfTheWeek > 7 || dayOfTheWeek < 1);
}

void validateOrder(int& order)
{
    do
    {
        cout << "What is your order ?" << endl;
        cin >> order;
    } while (order > 4 || order < 0);
}

void makeOrders(double& money, int dayOfTheWeek)
{
    int order;
    double totalSum = 0;
    int chipsCount = 0, pizzaCount = 0, burgerCount = 0, beerCount = 0;
    double chipsCost = 2, pizzaCost = 3, burgerCost = 3.5, beerCost = 6.66;
    int warningsCount = 0;

    do
    {
        validateOrder(order);
        if (order == 0)
            break;

        switch (order)
        {
        case 1: totalSum += chipsCost; chipsCount++; break; // chips
        case 2: totalSum += pizzaCost; pizzaCount++; break; // pizza
        case 3: totalSum += burgerCost; burgerCount++; break; // burger
        case 4: totalSum += beerCost; beerCount++; break; // beer
        }

        switch (dayOfTheWeek)
        {
        case 1:
        case 2:
        case 3: order == 1 ? totalSum *= 0.9 : totalSum = totalSum; break;
        case 4:
        case 5: totalSum *= 0.75; break;
        case 6:
        case 7: totalSum *= 1.3; break;
        }

        if (money - totalSum <= 0)
        {
            cout << "You don't have enough money!" << endl;
            warningsCount++;
            continue;
        }
        else
        {
            money -= totalSum;

            cout << "Total sum: " << totalSum << endl;
            cout << "Money left: " << money << endl;
        }

        if (warningsCount == 3)
            return;
    } while (order <= 4 && order >= 1);

    cout << chipsCount << " " << pizzaCount << " " << burgerCount << " " << beerCount << endl;
    cout << chipsCount * chipsCost << " " << pizzaCount * pizzaCost << " " 
        << burgerCount * burgerCost << " " << beerCount * beerCost << endl;
    cout << totalSum << endl;
    cout << money;
}

int main()
{
    double money;
    int dayOfTheWeek;

    validateInput(money, dayOfTheWeek);

    makeOrders(money, dayOfTheWeek);
}