#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void cmlsc(unsigned char x1[1025],unsigned char x2[1025],unsigned char a[1027][1027],short int n,short int m)
{
	for(int i=1;i<=n;i++)
	{
		a[i][0]='0';
	}

	for(int j=0;j<=m;j++)
	{
		a[0][j]='0';
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x1[i-1]==x2[j-1])
			{
				a[i][j]=a[i-1][j-1]+'1'-'0';
			}
			else
			if(a[i-1][j]>=a[i][j-1])
			{
				a[i][j]=a[i-1][j];
			}
			else
			{
				a[i][j]=a[i][j-1];
			}
		}
	}

}

void print_sol(unsigned char a[1027][1027],unsigned char x1[1025],unsigned char x2[1025],short int i,short int j)
{
	if(i==0||j==0)
	{
		return;
	}
	if(x1[i-1]==x2[j-1])
	{
		print_sol(a,x1,x2,i-1,j-1);
		fout<<x1[i-1]<<" ";
	}
	else
	if(a[i-1][j]>=a[i][j-1])
	{
		print_sol(a,x1,x2,i-1,j);
	}
	else
	{
		print_sol(a,x1,x2,i,j-1);
	}
}

int main()
{
	unsigned char x1[1025],x2[1025];
	short int n,m;
	unsigned char a[1027][1027];
	fin>>n>>m;

	for(int i=0;i<n;i++)
	{
		fin>>x1[i];

	}
	for(int j=0;j<m;j++)
	{
		fin>>x2[j];
	}
	cmlsc(x1,x2,a,n,m);
	fout<<a[n][m]<<endl;
	print_sol(a,x1,x2,n,m);


	return 0;
}
