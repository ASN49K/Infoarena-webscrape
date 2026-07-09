#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlscin");
ofstream g("cmlsc.out");
const int nmax=1024;
int a[nmax],b[nmax],m,n,s[nmax],o;
void subsir(int a[], int b[], int x, int y, int &o, int s[], int p)
{
	int poz=0;
	for(int i=p;i<=x;i++)
		{
				for(int j=1;j<=y;j++)
					if(a[i]==b[j])
					{
						if(poz<j)
						{
							o++;
							s[a[i]]=o;
							poz=j;
						}
					}
		}
}
void afis()
{
	g<<o<<'\n';
	for(int i=1;i<=o;i++)
		for(int j=1;j<nmax;j++)
			if(s[j]==i)
				g<<j<<' ';
}
void alb()
{
	for(int i=1;i<=nmax;i++)
		s[i]=0;
}
int main()
{
	int max,max1;
	f>>m>>n;
	for(int i=1;i<=m;i++)
		f>>a[i];
	for(int i=1;i<=n;i++)
		f>>b[i];
	f.close();
	if(m<n)
	{
		max=0;
		max1=0;
		for(int sf=1;sf<=m;sf++)
		{
			o=0;
			alb();
			subsir(a,b,m,n,o,s,sf);
			if(o>max)
			{
				max=o;
				max1=sf;
			}
		}
	}
	else
		if(m>n)
		{
			max=0;
			max1=0;
			for(int sf=1;sf<=n;sf++)
			{
				o=0;
				alb();
				subsir(a,b,m,n,o,s,sf);
				if(o>max)
				{
						max=o;
						max1=sf;
				}
			}
		}
		else
			if(m==n)
			{
				max=0;
				max1=0;
				for(int sf=1;sf<=n;sf++)
				{
					o=0;
					alb();
					subsir(a,b,m,n,o,s,sf);
					if(o>max)
					{
						max=o;
						max1=sf;
					}
				}
			}
	o=0;
	alb();
	subsir(a,b,m,n,o,s,max1);
	afis();
	g.close();
}
