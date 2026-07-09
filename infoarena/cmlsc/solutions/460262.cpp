#include <fstream>

using namespace std;

#define dim 1025

int v[dim][dim], a[dim], b[dim], c[dim];

int main()
{
	long m, n, i, j;
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	
	fin>>m >>n;
	
	for(i=1;i<=m;++i)
		fin>>a[i];
	for(i=1;i<=n;++i)
		fin>>b[i];
	
	
	
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=(v[i-1][j]>v[i][j-1]?v[i-1][j]:v[i][j-1]);
		}
	}
	int f=0;
	int s=v[m][n];
	
		
	i=m;
	j=n;
	while(s)
	{
		
		if(a[i]==b[j] && s==v[i][j])
		{
			c[s]=a[i];
			--i;
			--j;
			--s;
		}
		else
			if(v[i-1][j]==s)
				--i;
			else
				--j;
				
				
	/*if(a[i]==b[j])
	{
		c[f]=a[m];
		++f;
	}*/		
	//s=v[i][j];
	
	}
	/*if(v[m+1][n+1]==0)
	{
		fout<<"0";
		return 0;
	}*/
	
	fout<<v[m][n] <<'\n';
	for(i=1;i<=v[m][n];++i)
		fout<<c[i] <<" ";
	return 0;
}