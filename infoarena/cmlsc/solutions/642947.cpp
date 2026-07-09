#include <iostream>
#include <fstream>
using namespace std;
int a[1030],b[1030],m,n,x[1024][1030],p[1030];
void citire()
{
	ifstream fin("cmlsc.in");
	fin>>m>>n;
	for (int i=1;i<=m;i++)
	{
		x[i][0]=0;
		fin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{	
		x[0][i]=0;
		fin>>b[i];
	}
}
void dinamic()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else if(x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j];
			else x[i][j]=x[i][j-1];
}
void afisare()
{
	ofstream fout("cmlsc.out");
	fout<<x[m][n]<<'\n';
	int i=m,j=n,nr=0;
	while(x[i][j])
	{
		p[nr++]=b[j];
		i-=1;j-=1;
		while(x[i][j-1]==x[i][j])
			j--;
		while(x[i-1][j]==x[i][j])
			i--;
	}
	for(int i=nr-1;i>=0;i--)
		fout<<p[i]<<" ";
}
int main()
{
	citire();
	dinamic();
	afisare();
	return 0;
}