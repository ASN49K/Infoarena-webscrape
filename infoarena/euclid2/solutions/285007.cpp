#include <fstream.h>
void main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,k,p,a,b;
f>>n;
for (i=1;i<=n;i++)
	{
   f>>k>>p;
   a=k;
   b=p;
   while (a!=b)
   	{
   	if (a>b) a-=b;
      else b-=a;
   	}
   g<<a<<endl;
   }
f.close();
g.close();
}
