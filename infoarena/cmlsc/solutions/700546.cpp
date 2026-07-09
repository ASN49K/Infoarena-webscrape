#include<iostream>
#include<fstream>
#define nm 1040

using namespace std;

int a[nm],b[nm],c[nm][nm],n,m,mat[nm][nm],max_[nm];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire()
{
	f>>n>>m;
	for(int i=1;i<=n;++i)
		f>>a[i];
	for(int i=1;i<=m;++i)
		f>>b[i];
}

int rez(int r)
{
	int ct=0;
	int p=1;
	for(int t=r;t<=m;++t)
		for(int j=p;j<=n;++j)
			if(a[j]==b[t])
			{
				ct++;
				p=j;
				c[r][p]=a[j];
				j=n+1;
				if(p>n)
					return ct;
				break;
			}
	return ct;
}

int main()
{
	citire();
	for(int i=1;i<=m;++i)
		rez(i);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(c[i][j])
				max_[i]++;
	int asdf=0;
	int k;
	for(int i=1;i<=m;++i)
		if(max_[i]>asdf)
		{
			asdf=max_[i];
			k=i;
			break;
		}
	g<<asdf<<'\n';
	for(int i=1;i<=n;++i)
		if(c[k][i])
			g<<c[k][i]<<' ';
}
