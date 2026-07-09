#include<bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],i,j,d[1025][1025],l,c[1025];

int main()
{
	fin>>n>>m;
	for(i=0;i<n;++i)fin>>a[i];
	for(i=0;i<m;++i)fin>>b[i];
		for(i=0;i<n;++i)
			for(j=0;j<m;++j)
				if(a[i]==b[j])
					d[i][j]=1+d[i-1][j-1];
				else d[i][j]=max(d[i-1][j],d[i][j-1]);
	for(i=n-1,j=m-1;i>=0;)
		if(a[i]==b[j])c[++l]=a[i],--i,--j;
			else 
			if(d[i-1][j]<d[i][j-1])--j;
				else --i;
	fout<<d[n-1][m-1]<<"\n";
	for(i=d[n-1][m-1];i>0;--i)fout<<c[i]<<" ";	
	return 0;
}

