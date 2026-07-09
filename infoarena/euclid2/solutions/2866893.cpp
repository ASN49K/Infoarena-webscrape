#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int x, int y)
{
    if(!y)return x;
    else return euclid(y,x%y);
}
int a,b,t;
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
