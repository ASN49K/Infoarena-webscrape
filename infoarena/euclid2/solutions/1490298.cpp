#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
inline int turcu(int a, int b)
{
    int c;
    if (a<b) swap(a,b);
    while (b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int n,x,y;
int main()
{
    f>>n;
    for (int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<turcu(x,y)<<'\n';
    }
    return 0;
}
