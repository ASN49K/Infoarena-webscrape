#include<fstream.h>
long a,b,r,aux;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>a>>b;
if(a>b) {aux=a;a=b;b=aux;}
while(b)
 {r=a%b;
  a=b;
  b=r;
  }
g<<a;
f.close();
g.close();
return 0;
}
