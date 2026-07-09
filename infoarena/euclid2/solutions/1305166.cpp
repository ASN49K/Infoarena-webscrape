#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,i,n;

int eu(int a, int b)
{
	if(!b) return a;
	return eu(b,a%b);
}

int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		g<<eu(x,y)<<'\n';
	}
	f.close();
	g.close();
	return 0;
}