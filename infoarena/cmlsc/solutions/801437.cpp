#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[256],l,c,x[1024],y[1024],z[1024];
int main()
{
	f>>n>>m;
	for(int i = 0; i < n ; ++i)
	{
		f>>c;
		y[i] = c;
		a[c]++;
	}

	for(int i = 0; i < m; ++i)
	{
		f>>c;
		a[c]++;
		z[i] = c;
	}
	if(n < m)
	{
		for(int i = 0 ; i < n; ++i)
			if(a[y[i]] > 1)
				x[++l] = a[i];
	}
	else
	{
		for(int i = 0; i < m; ++i)
			if(a[z[i]] > 1)
				x[++l] = z[i];
	}
	g<<l<<'\n';
	for(int i = 1; i <= l; ++i)
		g<<x[i]<<" ";
	
	return 0;
}
	