#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int u(int a,int b)
{int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
return a;
}
int main()
{
	int a,i,d,n;
		f>>n;
		f>>a;
		a=d;
		for(i=2;i<=n;i++)
		{	f>>a;
			g<<u(d,a);
			a=d;
		}
		
	return 0;
}