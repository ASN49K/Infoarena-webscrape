#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int a[1024],b[1024],c[1024];
int main()
{short n,m;
short k=1,i,j,l;
f>>n>>m;
for(i=1;i<=n;i++)
	f>>a[i];
for(i=1;i<=m;i++)
	f>>b[i];

for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
 		for(l=1;l<=k;l++)
			if(a[i]==b[j] && a[i]!=c[l])
				{c[k]=a[i];k++;break;}
o<<k-1<<endl;
for(i=1;i<k;i++)
	o<<c[i]<<" ";
}

