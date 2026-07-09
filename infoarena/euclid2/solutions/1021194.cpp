#include<iostream>
#include<fstream>
using namespace std;

long cmmdc( long a, long b)
	{while(a*b>0)
		{if(a>b)
			a%=b;
		else
			b%=a;
		}
	return a+b;	
	}
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i;
long T,a,b;
f>>T;
for(i=0;i<T;i++)
	{f>>a>>b;
	g<<cmmdc(a,b)<<'\n';
	}
f.close();
g.close();
return 0;}
