#include <stdio.h>

using namespace std;
int i,t,a,r,b;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");


int main()
{

fscanf(f,"%d",&t);
for(i=1;i<=t;i++)
{
 fscanf(f,"%d%d",&a,&b);

 while(b>0)
 {
  r=b;
  b=a%b;
  a=r;
 }

 fprintf(g,"%d\n",a);
}

fclose(g);
return 0;
}
