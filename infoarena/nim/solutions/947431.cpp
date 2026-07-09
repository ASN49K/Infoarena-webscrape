#include<fstream>
using namespace std;

int i,n,t,s,x;

int main()
{
	ifstream f("nim.in");
	ofstream g("nim.out");
	f >> t;
	for (int w=1;w<=t;w++)
	{
		f >> n;
		s=0;
		for (i=1;i<=n;i++)
		{
			f >> x;
			s^=x;
		}
		if (s!=0)
			g << "DA\n";
		else g << "NU\n";
	}
	return 0;
}