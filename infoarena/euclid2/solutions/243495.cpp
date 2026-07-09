#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
using namespace std;
long euclid(int a,int b)
{ if (b==0)return a;
else euclid(b,a%b);
}

void main()
{long t,a,b;
f>>t;
for (int i=1;i<=t;i++)
 {f>>a>>b;
  g<<euclid(a,b)<<endl;
  } f.close();g.close();}