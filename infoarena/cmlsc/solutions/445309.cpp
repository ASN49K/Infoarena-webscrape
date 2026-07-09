#include<fstream.h>
#define max 1026
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
long m,n,i,j,k=0;
int a[max],b[max];
fin>>m>>n;

for(i=1;i<=m;i++)
 {
  fin>>a[i];
 }
 for(i=1;i<=n;i++)
 {
  fin>>b[i];
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
 
fout<<k<<"\n";

 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==b[j])
    {
       fout<<a[i]<<" ";
    } 
  }
 }
 return 0;
}