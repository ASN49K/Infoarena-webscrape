#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;

int Cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int a, b;
        fin >> a >> b;
        fout << Cmmdc(a, b) << '\n';
    }

    return 0;
}
