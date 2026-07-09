#include<fstream>
using namespace std;
int main()
{
	long n,a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	while(f>>a>>b)
	{	while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<'\n';
	}
	f.close();
	g.close();
	return 0;
}