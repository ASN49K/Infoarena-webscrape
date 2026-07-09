#include<fstream>
using namespace std;

int x,y,t;
int euclid(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	while(t--)
	{
		f>>x>>y;
		g<<euclid(x,y)<<"\n";
	}
	return 0;
}