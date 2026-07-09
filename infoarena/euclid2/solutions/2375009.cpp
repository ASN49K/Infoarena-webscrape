#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, n, r;

int main()
{
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        fin >> a >> b;
        if (a < b)
        {
            r = a;
            a = b;
            b = r;
        }
        while (b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
}
