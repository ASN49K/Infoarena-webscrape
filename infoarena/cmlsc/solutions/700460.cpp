#include<iostream>
#include<fstream>
#define nm 1040

using namespace std;

int a[nm],b[nm],c[nm],n,m;

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

int rez()
{
	int ct=0;
	int p=1;
	for(int t=1;t<=m;++t)
		for(int j=p;j<=n;++j)
			if(a[j]==b[t])
			{
				ct++;
				p=j;
				c[p]=a[j];
				if(p>n)
					return ct;
				break;
			}
	return ct;
}

int main()
{
	citire();
	g<<rez()<<'\n';
	for(int i=1;i<=n;++i)
		if(c[i]!=0)
			g<<c[i]<<' ';
}
