#include <fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t,a,b,k,i,r;
	f>>t;
	for (i=1;i<=t;i++)
	{
		f>>a>>b;
		if (a==0) {g<<0<<'\n'; break;}
		if (b==0) g<<0<<'\n';
		else if (b)
		{
		if (a>b)
		{
			r=a%b;
			while (r!=0)	
			{
				a=b;
				r=a%b;
				b=r;				
			}
			g<<b<<'\n';
		}
		else if (a<b)
		{
			r=b%a;
			while (b%a!=0)	
			{
				b=a;
				a=r;
				r=b%a;
				
			}
			g<<a<<'\n';
		}
		else if(a==b) g<<"cmmdc= "<<a<<'\n';
		}
	}
	f.close();
	g.close();
	return 0;
}
