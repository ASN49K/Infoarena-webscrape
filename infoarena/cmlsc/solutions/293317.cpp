#include<fstream.h>
ifstream intrare ("cmlsc.in");
ofstream iesire ("cmlsc.out");
int sol[1025][1025],a[1025],b[1025];
int min(int x, int y)
{
	if(x<=y) return x;
	else return y;
}
int max(int x, int y)
{
	if(x<=y) return y;
	else return x;
}
int main()
{
	int i,j,m,n;
	intrare>>m>>n;
	for(i=1;i<=m;i++)
		intrare>>a[i];
	for(i=1;i<=n;i++)
		intrare>>b[i];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i]==b[j]) sol[i][j]=min(sol[i-1][j],sol[i][j-1])+1;
			else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
		}
	}
	int var=sol[m][n];
	i=m; j=n;
	for(i=m;i>=0;i--)
	{
		for(j=n;j>=0;j--)
		{
			if(sol[i][j]==var) a[var]=b[j];
			else {j=-2;  var--;}
		}
	}
	iesire<<sol[m][n]<<"\n";
	for(i=1;i<=sol[m][n];i++)
		iesire<<a[i]<<" ";
	return 0;
}