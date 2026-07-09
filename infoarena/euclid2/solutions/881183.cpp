#include<fstream>
using namespace std;
ifstream f("euclid1.in");
ofstream g("euclid1.out");
int a,b,r,n;
int main()
{f>>n;
for(int i=1; i<=n; i++)
	{f>>a>>b;
	while(b!=0)
		{r=a%b;
		a=b;
		b=r;
		}
g<<a'\n';
}
g.close();
return 0;
}
