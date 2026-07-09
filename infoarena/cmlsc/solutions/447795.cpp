#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int M[1025][1025];
int pos[1025][1025];
int a[1025],b[1205];
int n,m;

void read();
void write(int x,int y);
void solve();

int main()
{
	read();
	solve();
	g<<M[n][m]<<'\n';
	write(n,m);
	f.close();
	g.close();
	return 0;
}

void read()
{
	int i;
	f>>n>>m;
	for (i=1;i<=n;f>>a[i],++i);
	for (i=1;i<=m;f>>b[i],++i);
}

void solve()
{
	int i,j;
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (a[i]==b[j]) 
				M[i][j]=M[i-1][j-1]+1;
			else
			{
				if (M[i][j-1]>M[i-1][j])
				{
					M[i][j]=M[i][j-1];
					pos[i][j]=1;
				}
				else 
				{
					M[i][j]=M[i-1][j];
					pos[i][j]=2;
				}
			}
}

void write(int x,int y)
{
	if (x&&y) 
	{
		if (pos[x][y]==0)
			write(x-1,y-1);
		else if (pos[x][y]==1)
			write(x,y-1);
		else 
			write(x-1,y);
		if (a[x]==b[y])
			g<<a[x]<<' ';
	}
}
