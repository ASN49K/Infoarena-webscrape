#include<fstream>
#define dim 1026
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,n,m,nr=0;
int a[dim],b[dim];
int mat[dim][dim];
int c[dim];
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
	while(i)
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
	return 0;
}
