#include<fstream>
#define dim 2500
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k,nr=0;
int mat[dim][dim];
int b[dim],c[dim];
int s;
int a[dim];
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	i=1;
	while(i<=n)
	{
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				if(mat[i-1][j]>mat[i][j-1])
					mat[i][j]=mat[i-1][j];
				else
					mat[i][j]=mat[i][j-1];
				i++;
}
	i=n,j=m;
	while(i!=0)
	{
		if(a[i]==b[j])
		{
			c[++nr]=a[i];
			i--;
			j--;
		}
		else
			if(mat[i-1][j]<mat[i][j-1])
				j--;
		else
			i--;
		g<<nr<<"\n";
		for(i=nr;i>=1;i--)
			g<<c[i]<<" ";
	}
	return 0;
}
