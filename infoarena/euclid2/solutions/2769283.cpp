#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int main()
{
    fin >> t;

    for (int test = 1; test <= t; test++)
    {
        fin >> a >> b;

        while (b != 0)
        {
            int rest = a % b;
            a = b;
            b = rest;
        }

        fout << a << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
