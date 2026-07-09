#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int a, int b)
{
    while (b)
    {
        int c = b;
        a %= b;
        b = a;
        a = c;
    }
    return a;
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