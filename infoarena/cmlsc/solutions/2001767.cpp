#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1026],b[1026],c[1026][1026],memo[1026],k;

int main(){
	int m,n;
	in>>m>>n;

	for(int i=1;i<=m;i++)in>>a[i];
	for(int i=1;i<=n;i++)in>>b[i];
	
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i]==b[j])
		{
			c[i][j]=c[i-1][j-1]+1;
			k++;
			memo[k]=a[i];
		}
		else c[i][j]=max(c[i-1][j],c[i][j-1]);
	}
	
	
	out<<c[m][n]<<'\n';
	for(int i=1;i<=k;i++)out<<memo[i]<<' ';
}
