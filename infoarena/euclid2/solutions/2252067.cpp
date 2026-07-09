#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
 
int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int main()
{
    int t, x, y;
    f>>t;
    while(t)
    {
        f>>x>>y;
        g<<euclid(x,y)<<'\n';
        t--;
    }
}