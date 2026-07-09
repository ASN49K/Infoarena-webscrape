#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[1024],l,c;
int main()
{
	f>>n>>m;
	for(int i = 0; i < n ; ++i)
	{
		f>>c;
		if(a[c] > 0)
			l++;
		a[c]++;
	}
	for(int i = 0; i < m; ++i)
	{
		f>>c;
		if(a[c] > 0)
			l++;
		a[c]++;
	}
	g<<l<<'\n';
	for(int i = 0 ; i < 1024; ++i)
		if(a[i] > 1)
			g<<i<<' ';
	return 0;
}
	