#include <bits/stdc++.h>
using namespace std;
int a,b,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
    int r;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}
int main()
{
    f>>t;
    while(t--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
