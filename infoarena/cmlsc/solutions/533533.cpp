#include<iostream>
#include<fstream>
#define MAX(a, b)((a)>(b) ? (a):(b))

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n, a[1025][1025], x[1025], y[1025], c[1025], bl;

int main()
{
	int i,j;
	fin>>m>>n;
	for(i=1;i<=m;i++)
		fin>>x[i];
	for(i=1;i<=n;i++)
		fin>>y[i];
		
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=MAX(a[i][j-1],a[i-1][j]);
	fout<<a[m][n]<<endl;
	for(i=m, j=n; i>0 && j>0;)
		if(x[i]==y[j])
		{
			c[bl]=x[i];bl++;
			i--;j--;
		}
		else
		{
			if(a[i-1][j]>a[i][j-1])
				i--;
			else
				j--;
		}
	
	for(i=bl-1;i>=0;i--)
		fout<<c[i]<<" ";
	
	
}
