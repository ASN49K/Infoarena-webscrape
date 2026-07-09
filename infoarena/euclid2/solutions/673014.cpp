#include <fstream>

using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long long int a,b,t;
	f>>t;
	for(t;t>0;t--)
	{
		f>>a;
		f>>b;
		while (a!=0&&b!=0)
		{
			if(a>b)
			{
				a=a%b;
			}
			else
			{
				b=b%a;
			}
		}
		if(a!=0)
		{
			g<<a;
		}
		else
		{
			g<<b;
		}
		g<<endl;
	}
}
	