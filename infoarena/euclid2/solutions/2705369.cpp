#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int gcd(int a, int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, x ,y;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> x >> y;
        fout << gcd(x, y) << "\n";
    }
    return 0;
}