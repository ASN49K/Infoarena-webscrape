#include<iostream.h>
#include<fstream.h>
long long e,s,a[10000],r[10000],i,v[10000],j,t=0;
int main ()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>s>>e;
for(i=1;i<=s;i++)
	f>>v[i];

	for(i=1;i<=e;i++)
		f>>a[i];
	
	f.close();
	for(i=1;i<=s;i++)
	  for(j=1;j<=e;j++)
		if(v[j]==a[i]){t++;r[t-1]=a[j];}
		g<<t<<endl;
		for(i=0;i<=t-1;i++)
			g<<r[i]<<" ";
g.close ();		
return 0;
}