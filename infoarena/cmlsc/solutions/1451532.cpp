#include<iostream>
#include<fstream>
using namespace std;

#define MAX 1025

int x[MAX],y[MAX],DP[MAX][MAX];

int v[MAX],st=0;;

int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int m,n,i,j;

	in>>n>>m;

	for(i=1;i<=n;i++)
		in>>x[i];
	cout<<'\n';
	for(i=1;i<=m;i++)
		in>>y[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		 if(x[i]==y[j])
			   DP[i][j]=DP[i-1][j-1]+1;
		 else
			   DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
	
	i=n,j=m;
	cout<<DP[i][j];
	while(DP[i][j])
	{
		while(DP[i][j] == DP[i][j-1])
			--j;
		while(DP[i][j] == DP[i-1][j])
			--i;
		v[++st]=x[i];
		--i;--j;
	}
	out<<st<<'\n';
	for(i=st;i>=1;i--)
		out<<v[i]<<" ";
	return 0;
}