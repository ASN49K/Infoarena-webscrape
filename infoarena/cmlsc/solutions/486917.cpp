#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[100001],b[100001],c[100][100],m,n;
int main()
{
	int i,j,max;
	fin>>m;
	fin>>n;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i-1][j]<c[i][j-1])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
			
	fout<<c[m][n]<<'\n';
return 0;
}