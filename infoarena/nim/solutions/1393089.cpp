#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int sumNim, number, numberTests;
int test;

int main()
{
    fin >> numberTests;

    while(numberTests--)
    {
        fin >> test;
        sumNim = 0;
        for(int i = 1; i <= test; i ++)
        {
            fin >> number;
            sumNim ^= number;
        }
        if(sumNim)
        {
            fout << "DA\n";
        }
        else
        {
            fout << "NU\n";
        }
    }
    return 0;
}

