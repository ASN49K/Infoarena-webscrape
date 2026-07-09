#include<iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int x, int y)
{
    int rest;
      while(y!=0)
      {
          rest=y;
          y=x%y;
          x=rest;
      }

    return x;
}

int main()
{
    long long n,x,y,t;

    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";

    }

    g.close();
    f.close();

   return 0;
}
