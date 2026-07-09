#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
  int a,b,r,cmmdc,t;
  in>>t;
  for (int i=1;i<=t;i++)
  {
    in>>a>>b;
    if (b>a)
    {
      r=a;
      a=b;
      b=r;
    }
    cmmdc=r=b;
    while (r>0)
    {
      cmmdc=r;
      r=a%b;
      a=b;
      b=r;
    }
    out<<cmmdc<<endl;
  }
  return 0;
}
