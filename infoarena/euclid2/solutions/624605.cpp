#include<fstream>
using namespace std;
int n,i,x,y,r;

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		r=0;
		while(y)
		{
			r=x%y;
			x=y;
			y=r;
		}
		
		g<<x<<"\n";
	}
	return 0;
}

