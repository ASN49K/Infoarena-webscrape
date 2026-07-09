#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[100],n;
int main()
{
int i,j,urm[100],lg[100],um,lgm,max;
f>>n;
for(i=1;i<=n;i++)
f>>a[i];
lg[n]=1;
urm[n]=0;
for(i=n-1;i>0;i--)
{
lgm=1;
um=0;
for(j=i+1;j<=n;j++)
if(a[i]<a[j] && lgm<=lg[j])
{
lgm=lg[j]+1;
um=j;
}
      lg[i]=lgm;
      urm[i]=um;
}
max=0;j=0;
for(i=1;i<=n;i++)
if(lg[i]>max)
{
max=lg[i];
j=i;
}
while(j!=0)
{
g<<a[j]<<" ";
j=urm[j];
}
f.close();
g.close();
return 0;
}