#include<stdio.h>

FILE *fin=freopen("euclid2.in","r",stdin),
     *fout=freopen("euclid2.out","w",stdout);
     
long n,m;

int t;

long cmmdc(long n,long m)
{
  if(m==0) return n;
  return cmmdc(m,n%m);
}
     
int main()
{
  
  scanf("%d",&t);
  for(int i=0; i<t; i++)
  {
    scanf("%ld %ld",&n,&m);
    printf("%d\n",cmmdc(n,m));
  }
  return 0;
}
