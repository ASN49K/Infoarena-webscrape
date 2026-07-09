#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long cmmdc(long a,long b)
     {if(!b)return a;
	return cmmdc(b,a%b);
	}

int main()
{long a,b,t;
f>>t;
for(long i=1;i<=t;i++)
{f>>a>>b;
g<<cmmdc(a,b)<<'\n';}
g.close();
f.close();
return 0;
}
