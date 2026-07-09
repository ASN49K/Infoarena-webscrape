#include <fstream>
using namespace std;

int a,b,c,t,i;
int euclid (int x, int y)
{
	if (y==0) return x;
	euclid (y, x%y);
}	
	
int main ()
{
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	f >>t;
	for (i=1; i<=t; i++)
	{
		f >>a>>b;
		g <<euclid (a,b)<<'\n';
	}
	return 0;
}
