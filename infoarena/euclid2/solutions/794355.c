#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{unsigned a,b,T,i;
f>>T;
for(i=0;i<T;i++)
{f>>a; f>>b;
if(a==b)
	g<<a<<'\n';
else 
{while(a!=b)
	{if(a>b)
		a=a-b;
	else b=b-a;}
g<<a<<'\n';
}}
f.close();
g.close();
return 0;
}

	