#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
long m,n,i,j,k;
int a[1026],b[1026];
f>>m>>n;

for(i=1;i<=m;i++)
 {
  f>>a[i];
 }
 for(i=1;i<=n;i++)
 {
  f>>b[i];
 }

 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==b[j])
    {
     k++;
    } 
  }
 }

g<<k<<"\n";

 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==b[j])
    {
       g<<a[i]<<" ";
    } 
  }
 }
}