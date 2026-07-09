#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int t;
int main()
{  f>>n;
for(int i=1;i<=n;i++)
{
    f>>a>>b;
    t=__gcd(a,b);
    g<<t<<'\n';
}
    return 0;
}
