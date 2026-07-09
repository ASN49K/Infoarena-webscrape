#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void cmlsc(int x1[],int x2[],int a[1024][1024],int b[1024][1024],int n,int m)
{	
	for(int i=1;i<=n;i++)
	{
		a[i][0]=0;	
	}

	for(int j=0;j<=m;j++)
	{
		a[0][j]=0;	
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x1[i-1]==x2[j-1])
			{
				a[i][j]=a[i-1][j-1]+1;
				b[i][j]=3;
			}
			else
			if(a[i-1][j]>=a[i][j-1])
			{
				a[i][j]=a[i-1][j];
				b[i][j]=2;
			}
			else
			{
				a[i][j]=a[i][j-1];
				b[i][j]=1;
			}
		}
	}
}

void print_sol(int b[1024][1024],int x[],int i,int j)
{
	if(i==0||j==0)
	{
		return;
	}
	if(b[i][j]==3)
	{
		print_sol(b,x,i-1,j-1);
		fout<<x[i-1]<<" ";
	}
	else
	if(b[i][j]==2)
	{
		print_sol(b,x,i-1,j);
	}
	else
	{
		print_sol(b,x,i,j-1);
	}
}

int main()
{
	int x1[1024],x2[1024],n,m;
	int a[1024][1024],b[1024][1024];
	for(int i=0;i<n;i++)
	{
		fin>>x1[i];
	}
	for(int j=0;j<m;j++)
	{
		fin>>x2[j];
	}
	cmlsc(x1,x2,a,b,n,m);
	fout<<a[n][m]<<endl;
	print_sol(b,x1,n,m);
	return 0;
}
