//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m;
int v1[1025];
int v2[1025];
int d[1025][1025];
int sol[1025];
int main() 
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>v1[i];
	}
	for(int i=1; i<=m; i++)
	{
		cin>>v2[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(v1[i]==v2[j])
			{
				d[i][j]=d[i-1][j-1]+1;		
			}
			else 
			{
				d[i][j]=max(d[i-1][j], d[i][j-1]);
			}
		}
	}
	cout<<d[n][m]<<"\n";
	int i=n;
	int j=m;
	int x=0;
	while(i>=1 && j>=1)
	{
		if(v1[i]==v2[j])
		{
			sol[x]=v1[i];
			i--;
			j--;
			x++;
		}
		else 
		{
			if(d[i-1][j]>d[i][j-1])
			{
				i--;
			}
			else j--;
		}
	}
	for(i=x-1; i>=0; i--)
	{
		cout<<sol[i]<<" ";
	}
}