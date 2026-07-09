#include "fstream.h"
using namespace std;
int main()
{long a,b,n,m,r;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>m;
 while(f>>n)
 {a=n;
  f>>b;
  r=a%b;
  while(r)
  {a=b;
   b=r;
   r=a%b;
  }
  g<<b<<endl;
 }
 f.close();
 g.close();
 return 0;
}

