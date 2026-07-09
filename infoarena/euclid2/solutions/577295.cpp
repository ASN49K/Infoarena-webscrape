# include <fstream.h>
using namespace std;
int main ()
{ int T,i,a,b,r;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for (i=1;i<=T;i++)
{ f>>a>>b;
  while (b)
  { r=a%b;
    a=b;
	b=r;
  }
  g<<a<<endl;
}
f.close();
g.close();
}
  