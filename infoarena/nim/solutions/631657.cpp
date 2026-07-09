#include<fstream>
using namespace std;
int n,t;

int main()
{
	int i,j,x,sxor;
	ifstream f("nim.in");
	ofstream g("nim.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>n;
		sxor=0;
		for(j=1;j<=n;j++)
		{
			f>>x;
			sxor=sxor^x;
		}
		if(sxor)
			g<<"DA\n";
		else
			g<<"NU\n";
	}
	f.close();
	g.close();
	return 0;
}
