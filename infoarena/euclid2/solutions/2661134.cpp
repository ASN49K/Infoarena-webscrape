#include <bits/stdc++.h>
using namespace std;
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
int main()
{
   int T,a,b;
   f>>T;
   while(T--)
   {
       f>>a>>b;
      g<<__gcd(a,b)<<'\n';
   }
    return 0;
}
