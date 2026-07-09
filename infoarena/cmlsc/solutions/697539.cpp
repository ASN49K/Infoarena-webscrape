#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int a[1050], b[1050],c[1050],d[1050];
int main()
{int n,m,i,j,k,lmax,s,p;
f>>n>>m;
for(i=1;i<=n;i++)
	f>>a[i];
for(i=1;i<=m;i++)
	f>>b[i];

lmax=0;
for(i=1;i<=n;i++)
	{p=1;
	 s=0;
	 for(j=i;j<=n;j++)
		for(k=p;k<=m;k++)
			if(a[j]==b[k])
				{s++;
				 c[s]=a[j];
				 p=k+1;
				}
	 if(s>lmax)
		{lmax=s;
	     for(j=1;j<=lmax;j++)
			d[j]=c[j];
		}
	}

g<<lmax<<endl;
for(i=1;i<=lmax;i++)
	g<<d[i]<<" ";
return 0;}