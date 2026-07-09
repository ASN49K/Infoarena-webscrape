#include<iostream>
#include<fstream>
#define MAX 1028
using namespace std;
fstream f("cmlsc.in",ios::in), g("cmlsc.out",ios::out);
int n,m;
int a[MAX],b[MAX],mat[MAX][MAX];
int max(int x,int y);
void parcurgere(int x,int y);
void pre();
int main()
{
	pre();
	parcurgere(m,n);
	return 0;
}
int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}
void parcurgere(int x,int y)
{
	if(x!=0 || y!=0)
	{	if(a[y]==b[x])
			parcurgere(x-1,y-1);
		else
			if(mat[x][y-1]>=mat[x-1][y] && y-1>0)
				parcurgere(x,y-1);
			else
				if(x-1>0)
					parcurgere(x-1,y);
		if(a[y]==b[x])
			g<<a[y]<<" ";
	}
}
void pre()
{
	int i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(a[j]==b[i])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
		}
	g<<mat[m][n]<<endl;
}