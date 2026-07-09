#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1026],b[1026],c[1026][1026],memo[1026];

int main(){
	int m,n;
	in>>m>>n;

	for(int i=1;i<=m;i++)in>>a[i];
	for(int i=1;i<=n;i++)in>>b[i];
	
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
		else c[i][j]=max(c[i-1][j],c[i][j-1]);
	}
	
	
	out<<c[m][n]<<'\n';
	
	int i=m,j=n,k=1;
	while(c[i][j])
	{
		while(c[i][j]==c[i][j-1])j--;
		while(c[i][j]==c[i-1][j])i--;
			memo[k]=b[j];
			i--;
			j--;
			k++;
	}
	for(int i=k-1;i>=1;i--)out<<memo[i]<<' ';
}
