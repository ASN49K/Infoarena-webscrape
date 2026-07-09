#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int n,a,b,d,c;
  f>>n;   ///citire date
  for(int i=1;i<=n;i++)
  {
        f>>a>>b;
        while(b!=0)
      {
          c=a%b;
          a=b;
          b=c;
      }
        g<<a<<endl;
  }


    return 0;
}
