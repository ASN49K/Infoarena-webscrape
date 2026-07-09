#include<fstream>
using namespace std;
long n,x,y;
long cmmdc(long x,long y)
{
  while(y)
  {
      int r=x%y;
      x=y;
      y=r;
  }
  return x;

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y);


    }
    f.close();
    g.close();
    return 0;
}
