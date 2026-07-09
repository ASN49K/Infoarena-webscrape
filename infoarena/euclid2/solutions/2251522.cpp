
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
int t;
while(b)
{
  t=b;
  b=a%b;
  a=t;
}
return a;
}
int main()
{
  int T,a,b;
  f>>T;
  for(int i=1;i<=T;i++)
  {
    f>>a>>b;
    g<<euclid(a,b)<<'\n';
  }
}
