#include<fstream>
using namespace std;
int m,n,a[1025],b[1025],d[1025][1025],i,j,x,v[1025];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

int main()
{
	
	fin>>m>>n;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else 
				d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	i=m;j=n;
	while(i)
	{
		if(a[i]==b[j])
			{v[++x]=a[i],i--,j--;}
		else if(d[i-1][j]<d[i][j-1]) j--;
		else i--;
	}
	
	for(i=x;i>=1;i--)
	{
		fout<<v[i]<<" ";
	}
	
}
