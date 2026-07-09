#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1024],n,m;
int v[1025][1025],r;

int main()
{
	fin>>n>>m;
	for (int i=1; i<=n; i++)
	{
		fin>>a[i];
	}
	for (int i=1; i<=m; i++)
	{
		fin>>b[i];
	}
	for(int i=n; i>=1; i--)
	{
	    for(int j=m; j>=m; j--)
	    {
	        if(a[j]!=b[i])
	        {
	            v[i][j]=max(v[i-1][j],v[i][j-1]);
	        }
	        else if(a[j]==b[i])
	        {
	            v[i][j]=1+v[i-1][j-1];
	        }
	    }
	}
	int l=v[n][m];
	fout<<l;
	
	
    

    return 0;
}