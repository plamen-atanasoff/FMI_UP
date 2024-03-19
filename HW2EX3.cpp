#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const size_t testWidth = 6;
const size_t testHeight = 5;

int testColony[testHeight][testWidth] = {
    {20, 20, 20, 15, 18, 10},
    {22, 21, 20, 19, 18, 14},
    {20, 20, 26, 16, 22, 42},
    {21, 25, 25, 20, 19, 41},
    {19, 20, 23, 43, 44, 44}
};

const unsigned int MAX_VALUE = 255;
const size_t BACTERY_PROPERTIES = 3;
const size_t ALL_POSSIBLE_MOVES_COUNT = 4;
int ALL_POSSIBLE_MOVES[ALL_POSSIBLE_MOVES_COUNT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

// each bactery has durability, productivity, adaptability (between 0 and 255)
typedef unsigned int bactery[3];

unsigned int validate(const char* property)
{
    unsigned int n;
    do
    {
        cout << "Enter " << property << ": ";
        cin >> n;
        cout << endl;
    } while (n > 255);

    return n;
}

void initMatrix(bactery** colony, size_t height, size_t width)
{
    for (size_t i = 0; i < height; ++i)
    {
        colony[i] = new bactery[width];
        for (size_t j = 0; j < width; ++j)
        {
            //cout << "Bactery " << i << j << endl;
            //colony[i][j][0] = validate("durability");
            //colony[i][j][1] = validate("productivity");
            //colony[i][j][2] = validate("adaptability");

            // for easier testing
            colony[i][j][0] = testColony[i][j];
            colony[i][j][1] = testColony[i][j];
            colony[i][j][2] = testColony[i][j];
        }
    }
}

void copyMatrix(bactery** modifiedColony, bactery** colony, size_t height, size_t width)
{
    for (size_t i = 0; i < height; ++i)
    {
        modifiedColony[i] = new bactery[width];
        for (size_t j = 0; j < width; ++j)
        {
            modifiedColony[i][j][0] = colony[i][j][0];
            modifiedColony[i][j][1] = colony[i][j][1];
            modifiedColony[i][j][2] = colony[i][j][2];
        }
    }
}

double getAverage(bactery& bactery)
{
    return (bactery[0] + bactery[1] + bactery[2]) / 3.00;
}

void printMatrix(bactery** colony, size_t height, size_t width)
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            double average = getAverage(colony[i][j]);
            if (average <= 9)
                cout << " ";
            cout << fixed << setprecision(2) << average << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void infectBactery(bactery& bactery)
{
    for (int i = 0; i < BACTERY_PROPERTIES; ++i)
    {
        bactery[i] = 0;
    }
}

bool bacteryIsInfectable(bactery& currBactery, bactery& previousBactery)
{
    if (abs(getAverage(currBactery) - getAverage(previousBactery)) <= 1.00)
        return true;
    else
        return false;
}

void infectRec(bactery** colony, bactery**& modifiedColony, int infRow, int infCol,
    bactery& previousBactery, int startRow, int startCol, unsigned int height, unsigned int width)
{
    if (infRow < 0 || infCol < 0 || infRow >= height || infCol >= width)
        return;
    if (!(startRow == infRow && startCol == infCol) && getAverage(modifiedColony[infRow][infCol]) == 0)
        return;
    if (!bacteryIsInfectable(colony[infRow][infCol], previousBactery))
        return;

    infectBactery(modifiedColony[infRow][infCol]);
    //printMatrix(modifiedColony, height, width);

    for (int i = 0; i < ALL_POSSIBLE_MOVES_COUNT; ++i)
    {   
        infectRec(colony, modifiedColony, 
            infRow + ALL_POSSIBLE_MOVES[i][0], infCol + ALL_POSSIBLE_MOVES[i][1], 
            colony[infRow][infCol], startRow, startCol, height, width);
    }
}

bool inputIsValid(size_t infRow, size_t infCol, size_t height, size_t width)
{
    return (infRow >= 0 && infRow < height) && (infCol >= 0 && infCol < width);
}

bactery** infect(bactery** colony, size_t height, size_t width, size_t infRow, size_t infCol)
{
    if (inputIsValid(infRow, infCol, height, width))
    {
        bactery** modifiedColony = new bactery* [height];
        copyMatrix(modifiedColony, colony, height, width);

        //printMatrix(modifiedColony, height, width);

        infectRec(colony, modifiedColony, infRow, infCol, 
            colony[infRow][infCol], infRow, infCol, height, width);

        return modifiedColony;
    }
    else
        return nullptr;
}

void deleteMatrix(bactery**& colony, size_t height)
{
    for (int i = 0; i < height; i++)
    {
        delete[] colony[i];
    }
    delete[] colony;
}

int main()
{
    //unsigned int width, height;
    //cin >> width >> height;
    
    //for easier testing
    unsigned int width = testWidth, height = testHeight;
    // for easier testing

    bactery** colony = new bactery * [height];
    initMatrix(colony, height, width);
    
    printMatrix(colony, height, width);

    // bactery to infect
    unsigned int row, col;
    cin >> row >> col;

    bactery** modifiedColony = infect(colony, height, width, row, col);
    printMatrix(modifiedColony, height, width);

    deleteMatrix(colony, height);
    deleteMatrix(modifiedColony, height);
}
