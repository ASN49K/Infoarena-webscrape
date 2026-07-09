#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{ int c;
  while (b)
  {c=a%b;
   a=b;
   b=c;
  }
 return a;
}
int main()
{int a,b,T,r,i;
 f>>T;
 for(i=0;i<T;i++)
  {
      f>>a>>b;
      r=euclid(a,b);
      g<<r<<endl;
  }
  f.close();
  g.close();
return 0;
}
