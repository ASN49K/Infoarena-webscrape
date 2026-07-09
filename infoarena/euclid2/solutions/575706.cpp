#include<fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int a,b,n,i;
int main()
{f>>n;
for (i=1;i<=n;i++)
	{f>>a>>b;
	while (a!=b)
		if (a>b)
			a=a-b;
		else
			b=b-a;
	g<<b<<'\n';
	}
f.close();
g.close();
return 0;
}