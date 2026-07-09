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
		r=a%b;
			while (r!=0)	
			{
				a=b;
				b=r;	
				r=a%b;
			}
			g<<b<<'\n';
	}
	f.close();
	g.close();
	return 0;
}
