#include <fstream>

using namespace std;

int n,m,a[1025],b[1025],i,lcs[1025][1025],op[1025][1025];

int lg(int x, int y)
{
	if (x>=n || y>=m) return 0;
	if (a[x]==b[y])
	{
		op[x][y]=1;
		return 1+lg(x+1,y+1);
	}
	int lg1=lg(x+1,y),lg2=lg(x,y+1);
	if (lg1>=lg2)
	{
		op[x][y]=2;
		return lg1;
	}
	else
	{
		op[x][y]=3;
		return lg2;
	}
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for (i=0;i<n;i++)
		f>>a[i];
	for (i=0;i<m;i++)
		f>>b[i];
	
	g<<lg(0,0)<<'\n';
	int x=0, y=0;
	while (x<n && y<m)
	{
		
		if (op[x][y]==1)
		{
			g<<a[x]<<' ';
			x+=1,y+=1;
		}
		else
			if (op[x][y]==2)
				x+=1;
			else
				y+=1;
	}
	
	f.close();
	g.close();
	return 0;
}
