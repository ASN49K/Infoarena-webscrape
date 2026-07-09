#include<fstream>
using namespace std;
int main()
{
  int a,b,T,i,cmmdc;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>T;
  for(i=1;i<=T;i++)
  {  f>>a>>b;

      while(a!=b)
      {
      if(a>b) a=a-b;
      else if(a<b) b=b-a;
      }
      cmmdc=a;
      g<<cmmdc<<"\n";}
}
