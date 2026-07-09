#include <stdio.h>
int main()
{   FILE *f=fopen("euclid2.in","r");
int N;
fscanf(f,"%d",&N);
int a,b;
FILE *g=fopen("euclid2.out","w");
for (;N;--N)
{   fscanf(f,"%d %d",&a,&b);
int m;
while (b!=0)
{   m=a%b;
a=b;
b=m;
}
fprintf(g,"%d\n",a);
}
fclose(g);
}