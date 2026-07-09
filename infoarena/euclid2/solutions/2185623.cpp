#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,x,y,Div;

int cmmdc(int a, int b)
{
   int r=0;
    if(a==0)
    return b;
    else
     if(b==0)
      return a;
     else
      while(b!=0)
      {
          r=a%b;
          a=b;
          b=r;
      }
    return a;
}
int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
