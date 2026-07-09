#include<iostream.h>
#include<fstream.h>
int i,j,n,a,b,t;
int main ()
{ifstream f("euclid2.in");
ofstream g ("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;
if(a>=b)for(j=1;j<=b;j++)
	if(b%j==0&&a%j==0)t=j;
if(a<b)for(j=1;j<=a;j++)
	if(b%j==0&&a%j==0)t=j;
g<<t<<endl;
}
}
