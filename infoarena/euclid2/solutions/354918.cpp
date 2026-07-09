#include <fstream.h>
using namespace std;
unsigned long cmmdc(unsigned long a, unsigned long b)
{unsigned long r; while(a%b!=0)
{r=a%b; a=b; b=r;}
return b;}

int main()
{ifstream f;
ofstream g;
unsigned long a,b,t,i;
f.open("euclid2.in");
g.open("euclid2.out");
f>>t;
for (i=1;i<=t;i++)
	{f>>a>>b; g<<cmmdc(a,b)<<endl;}
f.close();
g.close();
return 0;
}