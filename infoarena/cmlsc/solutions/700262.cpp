#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define dim 1024
int a[dim], b[dim], n, m;
int mat[dim][dim];

void read()
{
	int i;
	fin>>n >>m;
	for(i=1;i<=n;++i)
		fin>>a[i];
	for(i=1;i<=m;++i)
		fin>>b[i];
}

void solve()
{
	int i, j;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i]==b[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			
	fout<<mat[n][m]<<'\n';
}	

void back(int val, int x, int y)
{
	if(val!=0)
	{
		if(a[x]==b[y] && val==mat[x][y])
		{
			back(mat[x][y]-1,x-1,y-1);
			fout<<a[x]<<" ";
		}
		else
			if(mat[x-1][y]==val)
				back(mat[x][y],x-1,y);
			else
				back(mat[x][y],x,y-1);
	}
	
}

int main()
{
	read();
	solve();
	back(mat[n][m],n,m);
	
	return 0;
}