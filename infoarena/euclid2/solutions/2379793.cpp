#include <iostream>
FILE * fin = fopen("euclid2.in","r");
FILE * fout = fopen("euclid2.out","w");

int n;

long long cmmdc(long long a,long long b)
{
  if(b==0 ) return a;
  else
    return cmmdc(b,a%b);
}

int main()
{
  fscanf(fin,"%d",&n);
  for(int i=0;i<n;i++)
  {
    long long j,k;
    fscanf(fin,"%lld %lld",&j,&k);
    fprintf(fout,"%lld\n", cmmdc(j,k));
  }
}
