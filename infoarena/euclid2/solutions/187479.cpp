#include<fstream.h>

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main ()
{
    int k,i,n,m,a;
    fin>>k;
    for(i=1;i<=k;i++)
    {
                     fin>>n>>m;  
  while(n%m!=0)
    {
                 a=n%m;
                 n=m;
                 m=a;
                 }
                 fout<<m<<"\n";
                 }
                 return 0;
                 }
                 
