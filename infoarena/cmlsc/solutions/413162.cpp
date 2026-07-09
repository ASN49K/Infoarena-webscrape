#include <fstream>
using namespace std;
int v[1024][1024],a[1024],b[1024];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void scrie(int x,int y)
{
	if (!x || !y) return;
	if (a[x]==b[y])
	{
		scrie(x-1,y-1);
		out<<a[x]<<" ";
		return;
	}
	if (v[x][y-1]>=v[x-1][y])
	{
		scrie(x,y-1);
		return;
	}
	scrie(x-1,y);
}

int main()
{
	int n,m,i,j;
	in>>n>>m;
	for (i=1;i<=n;i++)
		in>>a[i];
	for (i=1;i<=m;i++)
		in>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
			{
			if (v[i-1][j]>=v[i][j-1])
				v[i][j]=v[i-1][j];
			else 
				v[i][j]=v[i][j-1];
			}
		}
	out<<v[n][m]<<"\n";
	scrie(n,m);
	return 0;
}
