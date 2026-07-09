#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string>

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a<b)?b:a)
#define abs(a) ((a<0)?-a:a)

#define INF 2147483647

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n,m;

int *a,*b;

vector<int> LCS()
{
	int **c;
	{
		c= new int*[n+1];
		for (int i=0; i<n+1; i++)
			c[i]=new int[m+1];
	}

	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
		{
			if (i*j==0)
				c[i][j]=0;
			else if (a[i-1]==b[j-1]) c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=max(c[i-1][j],c[i][j-1]);
		}

	vector<int> rez;

	rez.push_back(c[n][m]);

	for (int i=n,j=m; i;)
	{
		if (a[i]==b[j]) 
		{
			rez.push_back(a[i]);
			i--;
			j--;
		}
		else if (c[i-1][j]<=c[i][j-1]) j--;
		else i--;
	}

	return rez;
}

int main()
{
	fin>>n>>m;

	a=new int[n+1];
	b=new int[m+1];
	
	for (int i=1; i<=n; i++)
		fin>>a[i];

	for (int i=1; i<=m; i++)
		fin>>b[i];

	vector<int> sir=LCS();

	fout<<sir[0]<<'\n';
	for (int i=sir.size()-1; i; i--)
		fout<<sir[i]<<' ';

    return 0;
}
