#include<fstream>
using namespace std;
main()
    {
    int t,a,b,i,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
      f>>a>>b;
      if(a>b)
      {
    while(a%b!=0)
    {
      r=a%b;
      a=b;
      b=r;
    }
    g<<b<<endl;
      }
      else
      {
    while(b%a!=0)
    {
      r=b%a;
      b=a;
      a=r;
    }
    g<<a<<endl;
      }
    }
    }
