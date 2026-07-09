#include<iostream>
#include<fstream>
using namespace std;
unsigned T,a,b;
unsigned cmmdc(unsigned a, unsigned b)
{unsigned r;
if(a<b)
	{r=a;
	a=b;
	b=r;}
while(b)
	{r=a%b;
	a=b;
	b=r;
	}
return a;
}

int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(int i=1;i<=T;i++)
	{f>>a>>b;
	g<<cmmdc(a,b)<<'\n';
	}
f.close();
g.close();
}
