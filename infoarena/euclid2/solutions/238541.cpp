#include<stdio.h>
int a,b,n,i;
int cmmdc(int a, int b)
    {
    if (!b) return a;
       else return (b,a%b);
       } 
int main()
{
FILE *f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");
fscanf(f,"%d",&n);
for (i=1;i<=n;i++)
    {
    fscanf(f,"%d%d",&a,&b);
    fprintf(g,"%d\n",cmmdc(a,b));
    }
return 0;
}
          
