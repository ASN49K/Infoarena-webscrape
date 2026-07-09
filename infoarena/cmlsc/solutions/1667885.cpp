#include<bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],i,j,d[1025][1025],l,c[1025];

int main()
{
	fin>>m>>n;
	for(i=1;i<=m;++i)fin>>a[i];
	for(i=1;i<=n;++i)fin>>b[i];
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
	for(i=m,j=n;i;)
		if(a[i]==b[j])c[++l]=a[i],--i,--j;
			else 
			if(d[i-1][j]<d[i][j-1])
			--j;
			else --i;
	fout<<l<<"\n";
	for(i=l;i;--i)fout<<c[i]<<" ";	
	return 0;
}

