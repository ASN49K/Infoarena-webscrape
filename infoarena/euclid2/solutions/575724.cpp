#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r;
int main()
{f>>a>>b;
if (b==0)
	g<<a;
else
	{r=a%b;
	while (r!=0)
		{a=b;
		b=r;
		r=a%b;
		}
	if (b==1)
		g<<'0';
	else
		g<<b;
	}
f.close();
g.close();
return 0;
}
