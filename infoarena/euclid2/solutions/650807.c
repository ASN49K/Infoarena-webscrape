#include <stdio.h>
int cmmdc(int a,int b)
{
 if(a%b==0)
  return b;
 else
  return cmmdc(b,a%b);
}

int main()
{
 FILE *in,*out;
 in=fopen("euclid2.in","r");
 out=fopen("euclid2.out","w");
 int i,nr,n,m;
 fscanf(in,"%d",&nr);
 for(i=1;i<=nr;i++)
 {
  fscanf(in,"%d",&n);
  fscanf(in,"%d",&m);
  if(n>m)
   fprintf(out,"%d\n",cmmdc(n,m));
  else
   if(n<m)
    fprintf(out,"%d\n",cmmdc(m,n));
   else
    fprintf(out,"%d\n",m);
 }
 return 0;
}
