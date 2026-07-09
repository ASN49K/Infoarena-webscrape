//cel mai lung subsir comun
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max(int x, int y)
{
	if(x<y) return y;
	else
	return x;
}

int main()
{
	int x,y,n,i,j,a[999],b[999],c[999][999],v[999],m,p=1;
	fin>>n>>m;
	for(i=1;i<=n;++i)	fin>>a[i];
	for(j=1;i<=m;++j)	fin>>b[j];
	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i]==b[j])
			c[i][j]=c[i-1][j-1]+1;
			else
			c[i][j]=max(c[i][j-1],c[i-1][j]);
	fout<<c[n][m]<<'\n';
	
	i=n;	j=m;
	while(j!=0 && i!=0)
	{
		if(a[i]==b[i])
		{
			v[p]=a[i];
			i--;
			j--;
			p++;
		}
		else
		if(c[i-1][j]>c[i][j-1])	i--;
		else j--;
	
	}
	p--;
	for(i=p;i>=1;--i)	fout<<v[i]<<" ";
	fout<<'\n';
	
	return 0;
}
