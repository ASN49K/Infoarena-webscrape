#include <iostream>
#include <fstream>
using namespace std;

fstream fin("cmlsc.in",ios::in);
fstream fout("cmlsc.out",ios::out);
int m,n,i,j;	
int d[1025][1025];
int dela[1025][1025];
int s1[1025],s2[1025];	

int max(int a, int b)	{
	if (a>b) return a;
	return b;
}

int main(){

	fin>>m; fin>>n;
	
	for(i=1;i<=m;i++)	{
		fin>>s1[i]; 
	} 
	for(i=1;i<=n;i++)	{
		fin>>s2[i]; 
	}
	
	for(i=1;i<=m;i++)	{
		for(j=1;j<=n;j++)	{
			if (s1[i]==s2[j]) 	d[i][j]=d[i-1][j-1]+1; 				
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}

	for(i=1;i<=m;i++)	{
		for(j=1;j<=n;j++)	{
			cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}
	i=m; j=n;	
	fout<<d[m][n]<<"\n";
	while (i>0&&j>0)	{
		if (s1[i]==s2[j])	{
			fout<<s1[i]<<" ";
			i--;
			j--;
		}
		else if (d[i-1][j]>d[i][j-1]) i--;
		else j--;
	}
	fout.close();
	return 0;
}
