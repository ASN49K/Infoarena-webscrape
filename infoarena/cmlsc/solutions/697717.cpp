#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
char a[1024],b[1024],c[1024];
int main()
{short n,m;
short k=0,i,j;

f.get(a,100);
f.get();
f.get(b,100);
f.get();
n=strlen(a);
m=strlen(b);
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	if(a[i]==b[j]&&a[i]!=32&&strchr(c,a[i])==0)
	{c[k]=a[i];k++;}
c[k]=0;
o<<strlen(c)<<endl;
for(i=0;i<=k;i++)
	o<<c[i]<<" ";
}

