#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],n,m,v[1025][1025];
int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
void scrie(int i, int j)
{
	if(i==0||j==0)
		return;
	if(a[i]==b[j])
	{
		scrie(i-1,j-1);
		g<<a[i]<<" ";
	}
	else
	{
		if(v[i-1][j]>v[i][j-1])
			scrie(i-1,j);
		else
			scrie(i,j-1);
	}
}
int main()
{
	int i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i-1][j],v[i][j-1]);
		}
	}
	g<<v[n][m]<<"\n";
	scrie(n,m);
	g<<"\n";
	return 0;
}
