#include <fstream>

using namespace std;
int t,a,b,cmmdc(int,int);
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
   fin>>t;
   for(;t;t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
int cmmdc(int x,int y)
{
  int r;
  while(y)
  {
      r=x%y;
      x=y;
      y=r;
  }
  return r;
}
