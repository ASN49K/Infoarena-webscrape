#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;
int a,b;

int  gcd(int  x,int y)
{
    if(!y)
        return x;
    return gcd(x,x%y);
}

int main()
{

    f>>t;
    for(int i=1;i<=t;i++)
   {
       f>>a>>b;
    g<<gcd(a,b)<<'\n';
   }

    return 0;
}
