#include <bits/stdc++.h>
using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

int n;

int Euclid(int a, int b)
{
    int aux;
    while (b > 0)
    {
        aux = a;
        a = b;
        b = aux % b;
    }
    return a;
}

int main()
{
    fin >> n;
    int x, y;
    while (n--)
    {
        fin >> x >> y;
        fout << Euclid(x, y) << '\n';
    }
    return 0;
}
