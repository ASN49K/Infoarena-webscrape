# include <fstream>
using namespace std;
ifstream f ("nim.in");
ofstream g ("nim.out");
int t,x,k,i,n,s;
int main ()
{
	f>>t;
	for (k=1;k<=t;k++)
	{
		s=0;
		f>>n;
		for (i=1;i<=n;i++)
		{
			f>>x;
			s=s^x;
		}
		if (s>0)
			g<<"DA\n";
		else
			g<<"NU\n";
	}
	return 0;
}
