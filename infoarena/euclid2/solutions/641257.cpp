#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int u(int x,int y)
{int r;
	while(y)
	{
		r=x%y;
		x=y;
		y=r;
	}
return x;
}
int main()
{	
	int a,b,t,i;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<u(a,b)<<"\n";
	}		
	return 0;
}