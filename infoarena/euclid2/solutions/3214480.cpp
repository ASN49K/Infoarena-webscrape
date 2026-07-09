#include <fstream>
#include <queue>
#include <iostream>
#include <queue>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int da(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int q;
    fin >> q;
    while (q--)
    {
        int a, b;
        fin >> a >> b;
        int x = da(a, b);
        fout << x << "\n";
    }
    return 0;
}
