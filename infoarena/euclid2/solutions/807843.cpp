#include<stdio.h>
FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
int t,i,a,b;
int cmmdc(int x,int y)
{if ((!x)||(!y)) return x+y;
if (x>y) return cmmdc(y,x%y); return cmmdc(x,y%x);
}
int main()
{
fscanf(f,"%d",&t);
for (i=1;i<=t;i++)
{
fscanf(f,"%d %d",&a,&b);
fprintf(g,"%d\n",cmmdc(a,b));
}
return 0;
}
