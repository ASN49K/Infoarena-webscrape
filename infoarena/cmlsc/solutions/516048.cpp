#include<fstream.h>
#include<iostream.h>
int main()
{ifstream f("cmlsc.in");
ofstream h("cmlsc.out");	
	int a[1025],b[1025],n,m,k=0,v[1000];
f>>n;
f>>m;
for(int i=1;i<=n;i++)
	f>>a[i];

for(int j=1;j<=m;j++)
	f>>b[j];
for(int i=1;i<=n;i++)	
for(int j=1;j<=m;j++)
	if(a[i]==b[j])
		{k++;
	    v[k]=a[i];}
	n=k;
	h<<k<<endl;
	for(k=1;k<=n;k++)	
		h<<v[k]<<" ";

		
	
	return 0;}