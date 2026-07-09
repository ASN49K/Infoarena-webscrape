#include<bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1024],b[1024],i,j,d[1024][1024],l,c[1024];

int main()
{
	fin>>n>>m;
	for(i=0;i<n;++i)fin>>a[i];
	for(i=0;i<m;++i)fin>>b[i];
		for(i=0;i<n;++i)
			for(j=0;j<m;++j)
				if(a[i]==b[j])
					d[i][j]=1+d[i-1][j-1],c[l++]=a[i];
				else d[i][j]=max(d[i-1][j],d[i][j-1]);
	fout<<l<<"\n";
	for(i=0;i<l;++i)fout<<c[i]<<" ";	
	return 0;
}

