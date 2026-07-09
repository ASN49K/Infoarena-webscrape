#include <fstream>
using namespace std;

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t,i;
	long long a,b;
	f>>t;
	for(i=1;i<=t;i++)
	{	f>>a;
		f>>b;
		while(a!=b)
		{if(a>b)
			a=a-b;
		 else
			 b=b-a;
		}
		g<<a;
		g<<'\n';
	}
	f.close();
	g.close();
	return 0;
}