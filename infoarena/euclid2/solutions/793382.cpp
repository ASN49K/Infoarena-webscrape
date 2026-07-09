#include<fstream>
using namespace std;
int n,i,a,b,r;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<"\n";
	}
	return 0;
}
