#include <fstream>
using namespace std;


int euclid (int a,int b)
	{
	if (b==0) return a;
	return (b,a%b);
	}

int main ()
	{
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	int a,b,x;
	f>>x;
	for (int i=0; i<x; i++)
		{
		f>>a>>b;
		g<<euclid(a,b)<<'\n';
		}
	g.close();
	return 0;
	}