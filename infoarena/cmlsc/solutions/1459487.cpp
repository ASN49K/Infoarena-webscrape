#include <iostream>
#include <fstream>
#include <algorithm>

int** lcs(int x[], int rowCount, int y[], int colCount)
{
    //instantiate variables
    int** z = new int*[rowCount + 1];
    for (int i = 0; i < rowCount + 1; ++i)
        z[i] = new int[colCount + 1];

    //initialize matrix
    for (int i = 0; i < rowCount + 1; i++)
    {
        z[i][0] = 0;
    }
    for (int i = 0; i < colCount + 1; i++)
    {
        z[0][i] = 0;
    }

    //dynamic alg.
    for (int i = 1; i < rowCount + 1; i++)
    {
        for (int j = 1; j < colCount + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                z[i][j] = z[i - 1][j - 1] + 1;
            }
            else
            {
                z[i][j] = std::max(z[i][j - 1], z[i - 1][j]);
            }
        }
    }

    //for (int i = 0; i < rowCount + 1; i++)
    //{
    //    for (int j = 0; j < colCount + 1; j++)
    //    {
    //        std::cout << +z[i][j] << " ";
    //    }
    //    std::cout << "\n";
    //}

    return z;
}

int backtrack(int rowCount, int colCount, int** z, int* x, int* y, int i, int j, int* rez, int rezCount)
{
    if (i == -1 || j == -1)
    {
        return rezCount;
    }
    else
    {
        if (x[i] == y[j])
        {
            rez[rezCount] = x[i];
            rezCount++;
            return backtrack(rowCount, colCount, z, x, y, i - 1, j - 1, rez, rezCount);
        }
        else
        {
            if (z[i + 1][j] > z[i][j + 1])
            {
                return backtrack(rowCount, colCount, z, x, y, i, j - 1, rez, rezCount);
            }
            else
            {
                return backtrack(rowCount, colCount, z, x, y, i - 1, j, rez, rezCount);
            }
        }
    }
}

int main(int argc, int * argv[])
{
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open("cmlsc.in");
    outFile.open("cmlsc.out");

    if (inFile.is_open())
    {
        //initialize variables
        short lenX, lenY;
        inFile >> lenX >> lenY;
        int* x = new int[lenX + 1];
        int* y = new int[lenY + 1];

        //read the sequences
        for (int i = 0; i < lenX; i++)
        {
            inFile >> x[i];
        }
        for (int i = 0; i < lenY; i++)
        {
            inFile >> y[i];
        }

        //start the dynamic programming alg.
        int** z = lcs(x, lenX, y, lenY);
        int rez[1025];
        int rezCount = backtrack(lenX, lenY, z, x, y, lenX - 1, lenY - 1, rez, 0);

        ////print a solution
        if (outFile.is_open())
        {
            outFile << z[lenX][lenY] << "\n";
            for (int j = rezCount-1; j >= 0; j--)
            {
                outFile << +rez[j] << " ";
            }
        }

        for (int h = 0; h < lenX; h++)
        {
            delete[] z[h];
        }
        delete[] z;
    }

    inFile.close();
    outFile.close();

    return 0;
}