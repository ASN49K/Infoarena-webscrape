#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned int cmmdc(unsigned int x, unsigned int y)
{
    unsigned int r;
    if (x < y)
    {
        swap(x, y);
    }
    while (x % y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return y;
}

int main(void)
{
    unsigned int n, i, x, y;
    fin >> n;
    for (i = n; i; i--)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << endl;
    }
    return 0;
}