#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,i,a,b,c;
    f>>T;
    for(i=1;i<=T;i++)
    {
      f>>a>>b;
      if(a==b)
      g<<a<<endl;
      else if(a>b)
     {while(a%b!=0)
     {
         c=b;
         b=a%b;
         a=c;
      }
      g<<b<<endl;}
      else
      {
          while(b%a!=0)
          {
              c=a;
              a=b%a;
              b=c;
          }
          g<<a<<endl;

      }
    }
    f.close();
    g.close();
    return 0;
}
