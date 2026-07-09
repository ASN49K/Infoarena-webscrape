#include<iostream.h>
#include<stdio.h>
int main ()
{unsigned long t, a, b;
int i;
FILE *f,*g;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%ld",&t);
for(i=1;i<=t;i++)
{fscanf(f,"%ld%ld",&a,&b);
do
{if(a>b)
a=a-b;
else
b=b-a;}
while(a!=b);
fprintf(g,"%ld\n",a);
}
fclose(f);
fclose(g);
return 0;
}