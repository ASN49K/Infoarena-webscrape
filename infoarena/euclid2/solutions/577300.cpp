# include <fstream.h>
using namespace std;
int main ()
{ int T,i,a,b;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for (i=1;i<=T;i++)
{ f>>a>>b;
  while (b!=a)
  { if (a>b)
       a=a-b;
   else
     b=b-a;
  }
  g<<a<<endl;
}
f.close();
g.close();
}
  