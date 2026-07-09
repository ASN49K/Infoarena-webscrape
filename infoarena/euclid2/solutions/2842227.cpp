#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i;
    int a,b;
    f>>n;
    for(i=0;i<n;++i)
    {
        f>>a>>b;
        g<<__gcd(a,b)<<"\n";
    }
}