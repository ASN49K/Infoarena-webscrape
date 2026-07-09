#include <iostream>
#include <fstream>
#define DIM 101
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int cmmdc(int x, int y)
{
    if (!y)
        return x;
    return cmmdc(y, x % y);
}

int main()
{
    fin >> T;
    for (int i = 1; i <= T; i++)
        fin >> a >> b, fout << cmmdc(a, b) << endl;
    return 0;
}