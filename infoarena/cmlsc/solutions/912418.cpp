#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1024],t[1024],n,m,i,j,maxim,d[1024][1024],s[1024];
int main()
{f>>m>>n;
for(i=1;i<=m;i++)
	f>>v[i];
for(i=1;i<=n;i++)
	f>>t[i];
for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		if(v[i]==t[j])
			d[i][j]=d[i-1][j-1]+1;
		else d[i][j]=max(d[i][j-1],d[i-1][j]);
i=m;
j=n;
int nr=0;
while(i!=0&&j!=0)
	if(v[i]==t[j])
		{nr++;
		s[nr]=v[i];
		i--;
		j--;}
	else if(d[i-1][j]<d[i][j-1])
				j--;
			else i--;
g<<nr<<endl;	
for(i=nr;i>=1;i--)
	g<<s[i]<<" ";
}