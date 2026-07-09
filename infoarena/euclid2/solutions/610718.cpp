#include <fstream.h>

main()
{long int T,a[100000],b[100000],i,c;
freopen("euclid2.1n","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&T);
for(i=1;i<=T;i++)
{scanf("%d%d",&a[i],&b[i]);
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
printf("%d\n",b[i]);
else
printf("%d\n",a[i]);}
}