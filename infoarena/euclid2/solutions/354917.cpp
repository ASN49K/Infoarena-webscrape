#include <fstream.h>
using namespace std;
int cmmdc(int a, int b)
{int r; while(a%b!=0)
{r=a%b; a=b; b=r;}
return b;}

int main()
{ifstream f;
ofstream g;
int a,b,t,i;
f.open("euclid2.in");
g.open("euclid2.out");
f>>t;
for (i=1;i<=t;i++)
	{f>>a>>b; g<<cmmdc(a,b)<<endl;}
f.close();
g.close();
return 0;
}