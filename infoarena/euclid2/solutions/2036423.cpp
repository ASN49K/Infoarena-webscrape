#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int x,int y)
{
    if(y==0)
        return x;
    return cmmdc(y,x%y);
}
int main()
{
  int T,a,b;
  f>>T;
  while(T)
  {
      f>>a>>b;
      g<<cmmdc(a,b)<<'\n';
      T--;
  }

    return 0;
}
