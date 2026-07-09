#include<iostream.h>
#include<fstream.h>
int a,s,t,b,n,i;
int euclid (int a, int b)
{if(!b)return a;
return euclid(b,a-b*(a/b));
}
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");

	f>>n;
for(i=1;i<=n;i++)
	{f>>s>>t;
g<<euclid(s,t)<<'\n';
}
}