#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long t,i,x,y;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>x>>y;
        fout<<__gcd(x,y)<<'\n';
    }
    return 0;
}
