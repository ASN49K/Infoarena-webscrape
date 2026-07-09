#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;

long long euclid(long long a,long long b)
{
    if(a==0 || b==0)
        return a+b;
    else
    {
        long long r;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        return b;
    }
}

int main()
{
  f>>t;
  for(int i=1;i<=t;i++)
  {
      long long x,y;
      f>>x>>y;
      g<<euclid(x,y)<<'\n';
  }
return 0;
}
