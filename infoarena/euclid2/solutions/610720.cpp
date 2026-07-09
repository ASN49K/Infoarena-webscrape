#include<fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

main()
{long int T,a[100000],b[100000],i,c;
f>>T;
for(i=1;i<=T;i++)
{f>>a[i]>>b[i];
do
{if(a[i]>b[i])
{c=a[i];
a[i]=b[i];
b[i]=c%b[i];}
else
{c=b[i];
b[i]=a[i];
a[i]=c%a[i];}}while(a[i]!=0&&b[i]!=0);
if(a[i]==0)
g<<b[i];
else
g<<a[i];}
}