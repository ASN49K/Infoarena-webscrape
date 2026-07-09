#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int x,int y)
{
    while(y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}

void solve()
{
    int n,x,y;
    fin>>n;
    while(fin>>x>>y)
        fout<<gcd(x,y)<<"\n";
}

int main()
{
    solve();
    return 0;
}
