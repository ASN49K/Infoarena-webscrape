#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        int d=__gcd(a,b);
        fout<<d<<'\n';
    }
    return 0;
}
