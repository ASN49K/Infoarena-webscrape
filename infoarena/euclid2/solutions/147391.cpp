#include<stdio.h>
int main()
{long a,b,r;

FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

fscanf(f,"%ld %ld",&a,&b);

r=a%b;
while(r)
{a=b;
 b=r;
 r=a%b;}

fprintf(g,"%ld",b);

fclose(f);
fclose(g);
return 0;
}