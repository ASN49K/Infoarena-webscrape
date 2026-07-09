#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1200],b[1200],D[1200][1200],i,j;

int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>a[i];
	for(i=1;i<=m;i++)
		fin>>b[i];
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			D[i][j]=0;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				D[i][j]=1+D[i-1][j-1];
			else
				D[i][j]=max(D[i-1][j],D[i][j-1]);
		}
		
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			fout<<D[i][j]<<" ";
		fout<<"\n";
	}*/
		
	fout<<D[n][m];	
	return 0;
}