#include<bits/stdc++.h>

using namespace std;

ifstream f ("euclid2.in");
ofstream g("euclid2.out");

bool p[2000001];
int t,a,b;

int euc(int a , int b)
{
   if (!b)
     return a;
   return (b,b%a);
}

int main()
{
    f>>t;
    while (t--)
    {
      f>>a>>b;
      g<<euc(a,b)<<'\n';
    }
}
