#include <fstream>
using namespace std;

int main()
{
	unsigned short x,i,a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>x;
	for(i=1;i<=x;i++)
	{
		f>>a>>b;
		while(b!=0)
		{
			r=b;
			b=a%b;
			a=r;
		}
		g<<a<<endl;
	}
	f.close();
	g.close();
}