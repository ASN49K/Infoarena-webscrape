#include<stdio.h>

FILE *fin=freopen("euclid2.in","r",stdin),
     *fout=freopen("euclid2.out","w",stdout);
     
long n,m;

long cmmdc(long n,long m)
{
  if(n>m) 
    return cmmdc (m,n-m);
  if(m>n)
    return cmmdc (n,m-n);
  if(n==m) 
    return n;
}
     
int main()
{
  scanf("%ld %ld",&n,&m);
  printf("%d",cmmdc(n,m));
  return 0;
}
