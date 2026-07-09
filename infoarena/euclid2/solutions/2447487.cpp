#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

inline int cmmdc(int a, int b)
{
    int r;
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n, x, y;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x, y)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
