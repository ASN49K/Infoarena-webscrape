#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	int n,i,a,b;
	f>>n;
	for(i=0;i<n;i++)
	{
		f>>a>>b;
		while(a!=b)
			if(a>b)a-=b;
		else
			b-=a;
		g<<a<<'\n';
	}
	f.close();g.close();
	return 0;
}
