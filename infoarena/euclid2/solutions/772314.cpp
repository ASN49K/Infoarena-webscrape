#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,t,x,y;
int euclid(int a,int b)
{
	if (b==0) return a;
	else return euclid(b,a%b);
}
int main()
{
	f>>t;
	for(i=1;i<=t;++i)
	{
		f>>x>>y;
		g<<euclid(x,y)<<'\n';
	}
	
	f.close();g.close();
	return 0;
}