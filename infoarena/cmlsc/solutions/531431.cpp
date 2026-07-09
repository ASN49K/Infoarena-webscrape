#include<fstream.h>
#include<iostream.h>
int main()
{int a[2000],b[2000],i,j,n,m,k=0,z=0,v[2000],u=0;
ifstream f("cmlsc.in");
ofstream h("cmlsc.out");	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		if(b[i]==a[j])
		{	
			if(j>u)
			{z++;	
		v[z]=b[i];
		u=j;}}
		
		h<<z<<endl;
		for(i=1;i<=z;i++)
			h<<v[i]<<" ";	
	return 0;}