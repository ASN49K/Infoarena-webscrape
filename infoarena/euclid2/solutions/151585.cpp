#include <stdio.h>
int main ()
{FILE *f,*fout;
 f=fopen("euclid2.in","r");
 fout=fopen("euclid2.out","w");
 long a,b,r;
 fscanf(f,"%ld%ld",&a,&b);

 while(b)
 {r=a%b;
  a=b;
  b=r;
 }
 fprintf(fout,"%ld",a);
 return 0;
}