#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid.out");
int euclid(int a, int b)
	{
   if (b==0)
   	return a;
   else
   	return euclid(b, a%b);
   }
int main()
{
int a, b, n, i;
f>>n;
for (i=1;i<=n;i++)
   {
   f>>a>>b;
   g<<euclid(a, b)<<"\n";
   }
f.close();
g.close();
return 0;
}
