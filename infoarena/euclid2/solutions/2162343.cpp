#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, c, t;

int gcd(int a, int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    fin>>t;
    for(int q=1; q<=t; ++q)
    {
        fin>>a>>b;
        fout<<gcd(a, b)<<"\n";
    }
    return 0;
}
