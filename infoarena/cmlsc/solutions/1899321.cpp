#include<bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int g[1030],d[1030],c[1030][1030],rs[1030],n,m,i,j,k=0;

int main()
{
	fin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
		fin>>g[i];
	}
	for(i=1;i<=m;i++)
	{
		fin>>d[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(g[i]==d[j]) c[i][j]=1+c[i-1][j-1];
			else
			c[i][j]=max(c[i-1][j],c[i][j-1]);
		}
	}

	for(i=n,j=m;i;)
	{
		if(g[i]==d[j])
		{
			rs[++k]=g[i];
			i--;
			j--;
		}
		else
		if(c[i-1][j]<c[i][j-1])
		j--;
		else i--;
	}
	fout<<k<<"\n";
	for(i=k;i;i--)
	{
		fout<<rs[i]<<" ";
	}
	
	return 0;
}
