#include<iostream>
#include<fstream>
using namespace std;

unsigned cmmdc(unsigned a, unsigned b)
{unsigned r;

while(b)
	{r=a%b;
	a=b;
	b=r;
	}
return a;
}

int main()
{unsigned T,a,b;
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
