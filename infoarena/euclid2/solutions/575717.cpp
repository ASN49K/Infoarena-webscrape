#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i,t,d;
int main()
{f>>n;
for (i=1;i<=n;i++)
	{f>>a>>b;
	t=1;
	if (a>b)
	for (d=2;d<=a;d++)
	while (a%d==0&&b%d==0)
		{a=a/d;
		b=b/d;
		t=t*d;
		}
	else
	for (d=2;d<=b;d++)
	while (a%d==0&&b%d==0)
		{a=a/d;
		b=b/d;
		t=t*d;
		}
	g<<t<<'\n';
	}
f.close();
g.close();
return 0;
}