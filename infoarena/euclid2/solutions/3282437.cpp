#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int x, int y)
{
    if (x % y == 0)
        return y;

    return Euclid(y, x % y);
}

int main()
{
    int t;
    fin >> t;

    while (t--)
    {
        int a, b;
        fin >> a >> b;
        fout << Euclid(a, b) << '\n';
    }

}
