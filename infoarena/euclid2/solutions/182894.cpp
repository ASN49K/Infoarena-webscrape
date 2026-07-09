#include<stdio.h>
FILE *f=fopen("euclid2.in","r"),
     *g=fopen("euclid2.out","w");
int cmmdc(int a,int b)
{
  if(!b) return a;
  return cmmdc(b,a%b);
}
int n,i,a,b;
int main()
{ fscanf(f,"%d",&n);
  for(i=1;i<=n;++i) { fscanf(f,"%d %d",&a,&b);
                      fprintf(g,"%d\n",cmmdc(a,b));
                    }
  fclose(f);
  fclose(g);
  return 0;
}
