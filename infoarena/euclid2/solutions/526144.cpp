#include <iostream>
#include <fstream>
using namespace std;

int cmmdc (int a,int b)
{
int d,D=1;
if (a>b) {d=b;
		  b=a;
		  a=d;}
d=2;
while (d<=a) {if (a%d==0) {a=a/d;
						   if (b%d==0) {b=b/d;
										D=D*d;}
			              }
			  else d++;}
return D;
}

int main (void)

{
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);

int T,d[200000],i;
f>>T;
for (i=1;i<=T*2;i++)
	f>>d[i];
for (i=1;i<=T*2;i=i+2)
	g<<cmmdc(d[i],d[i+1])<<"\n";
g.close();
return 0;
}
