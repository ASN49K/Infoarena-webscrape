#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int r = a % b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int t, x, y;
    fin >> t;
    
    for(int i = 1; i <= t; ++i)
    {
        fin >> x >> y;
        fout << euclid(x, y)  << '\n';
    }
}