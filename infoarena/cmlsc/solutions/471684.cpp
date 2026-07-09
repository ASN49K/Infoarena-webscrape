#include <iostream>
#include <fstream>
using namespace std;

fstream fin("cmlsc.in",ios::in);
fstream fout("cmlsc.out",ios::out);
int m,n,i,j;	
int d[1025][1025];
int dela[1025][1025];
int s1[1025],s2[1025],s[1030],c;	

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
			if (d[i-1][j]>d[i][j-1])	{
				d[i][j]=d[i-1][j];
				dela[i][j]=3;
			}
			else 	{
				d[i][j]=d[i][j-1];
				dela[i][j]=1;
			}
			if (s1[i]==s2[j]/*&&d[i-1][j-1]+1>d[i][j]*/) {d[i][j]=d[i][j]+1; /*dela[i][j]=2;*/ }
		}
	}
	dela[1][1]=4;
	i=m; j=n;	
	fout<<d[m][n]<<"\n";
c=1;
	while (i>0&&j>0)	{
		if (s1[i]==s2[j])	{	
			s[c++]=s1[i];			
		}
		if (dela[i][j]==1)	
			j--;
		else if (dela[i][j]==3)
			i--;
	}
	while (c>0) 
	{fout<<s[c--]<<" ";}
	fout.close();
	return 0;
}
