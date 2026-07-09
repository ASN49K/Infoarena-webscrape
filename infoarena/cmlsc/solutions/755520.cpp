#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,i,j;
int a[1030],b[1030],t[1030],c[1030][1030],k; 

int main()
{
	fin>>m>>n;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j] = c[i-1][j-1]+1;
			else
				if(c[i-1][j]>c[i][j-1])
					c[i][j] = c[i-1][j];
				else
					c[i][j] = c[i][j-1];
	fout<<c[m][n]<<'\n';
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i] == b[j])
				t[++k] = a[i];
	for(i=1;i<=k;i++)
		fout<<t[i]<<' ';
	return 0;
}