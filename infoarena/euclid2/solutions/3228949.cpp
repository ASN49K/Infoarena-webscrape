#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int c, a, b;
int gcd(int n, int m)
{
    int r=0;
    while(m!=0)
    {
        r=n%m;
        n=m;
        m=r;
    }
    return n;
}

int main()
{
    fin>>c;
    for(int i=1; i<=c; i++)
    {
        fin>>a>>b;
        fout<<gcd(a, b)<<'\n';
    }
    return 0;
}

