#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    return (b, b % a);
}

int main()
{
    int t, a, b;
    fin >> t;
    while (t--)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
    return 0;
}
