#include <bits/stdc++.h>
using namespace std;


int  gcd(int  x,int y)
{
    if(!y)
        return x;
    return gcd(y,x%y);
}

int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;
int a,b;
    f>>t;
    for(int i=1;i<=t;i++)
   {
       f>>a>>b;
    g<<gcd(a,b)<<'\n';
   }

    return 0;
}
