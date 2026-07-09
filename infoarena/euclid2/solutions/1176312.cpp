#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int x,y,q,t;

 int cmmdc(int a, int b)
{ if (!b) return a;
  return (b,a%b);
}
int main()
{f>>q;
 for (t=1;t<=n;t++)
  {f>>x>>y;
   g<<cmmdc(x,y)<<'\n';
  }
    return 0;
}
