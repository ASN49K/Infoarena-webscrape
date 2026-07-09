#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,a,b;

int gcd(int x,int y)
{
    if(!y)
        return x;
    return gcd(x,x%y);
}

int main()
{

    f>>T;
    for(int i=1;i<=T;i++)
   {
       f>>a>>b;
    f<<gcd(a,b)<<endl;
   }

    return 0;
}
