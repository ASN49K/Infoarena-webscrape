#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x, int y)
{
  if (y==0) return x;
  return cmmdc(y,x%y);
}

int main()
{
  unsigned int a,b,r,t;
  in>>t;
  for (int i=1;i<=t;i++)
  {
    in>>a>>b;
    out<<cmmdc(a,b)<<endl;
  }
  return 0;
}
