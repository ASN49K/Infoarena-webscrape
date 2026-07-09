#include <stdio.h>

long euclid(long a,long b)
{
if(b==0) return a;
return euclid(b, a%b);
}

int main()
{
long a,b;
FILE *f;
f=fopen("euclid2.in","r");
fscanf(f,"%d %d",&a,&b);
fclose(f);
f=fopen("euclid2.out","w");
fprintf(f,"%d\n",euclid(a,b));
fclose(f);
return 0;
}
