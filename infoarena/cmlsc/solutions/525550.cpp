#include<fstream.h>
#include<iostream.h>
int main()
{int a[2000],b[2000],i,j,n,m,k=0,z=0,v[2000];
ifstream f("cmlsc.in");
ofstream h("cmlsc.out");	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(a[i]==b[j])
		{	k++;
		z++;	
		v[z]=a[i];}
		n=z;
		h<<k<<endl;
		for(i=1;i<=n;i++)
			h<<v[i]<<" ";
	
	return 0;}