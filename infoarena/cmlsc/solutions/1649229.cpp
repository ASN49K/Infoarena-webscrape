#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
unsigned m,n,i,j,k,s[1025],v1[1025],v2[1025],d[1025][1025];
int main()
{
	fin>>m>>n;
	
	for(i=1;i<=m;i++)
	{
		fin>>v1[i];
	}
	for(j=1;j<=n;j++)
	{
		fin>>v2[j];
	}
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(v1[i]==v2[j])
			{
				d[i][j]=d[i-1][j-1]+1;
			}
			else
			{
				d[i][j]=max(d[i-1][j],d[i][j-1]);
			}
		}
	}
	
	for(i=m,j=n;i;)
	{
		if(v1[i]==v2[j])
		{
			s[++k]=v1[i];
			i--;
			j--;
		}
		else if(d[i-1][j]<d[i][j-1])
			j--;
		else
			i--;
	}
	fout<<d[m][n]<<"\n";
	for(i=k;i>0;--i)
	{
		fout<<s[i]<<" ";
	}
	return 0;
	
	
}
