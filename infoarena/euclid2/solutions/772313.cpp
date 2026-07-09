#include <fstream>
#define LE 1000000
using namespace std;
ifstream f("pietre.in");
ofstream g("pietre.out");
int a[LE*2],fr[2*LE],i,d,t,x,y;
int main()
{
	d=1;
	for(i=1;i+d<=LE;++i)
	{
		if (fr[i]==0) 
		{
	    	fr[i+d]=1;fr[i]=1;
	    	a[i]=i+d;a[i+d]=i;
			++d;
		}
	}
	f>>t;
	for(i=1;i<=t;++i)
	{
		f>>x>>y;
		if (a[x]==y) g<<2; else g<<1;
		g<<'\n';
	}
	f.close();g.close();
	return 0;
}