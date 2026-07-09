#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,t,i;
int main()
{
  f>>t;
  for(i=1;i<=t;++i)
  {
      f>>x>>y;
      while(x!=y)
        if(x>y)
            x=x-y;
        else
            y=y-x;
      g<<x<<'\n';
  }
  g.close();
  return 0;
}

