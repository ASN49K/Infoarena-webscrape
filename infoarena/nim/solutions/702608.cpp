#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");.
int t,n;
int main()
{
	f>>t;
	for(int i=0;i<t;i++)
	{
		f>>n;
		int s=0,x;
		for(int j=0;j<n;j++)
		{
			f>>x;
			s^=x;
		}
		if(s)
			g<<"DA\n";
		else
			g<<"NU\n";
	}
	return 0;
}