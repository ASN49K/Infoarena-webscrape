#include <stdio.h>
#include <stdlib.h>
int euclid(int a, int b)
{

    if(a==b)
    return a;
    if(a>b)
    return euclid(a-b,b);
    if(a<b)
    return euclid(a,b-a);
}
int main()
{
  int a,b,n,i;
  FILE *f,*g;
  f=fopen("euclid2.in","r");
  g=fopen("euclid2.out","w");
  fscanf(f,"%d",&n);
 for(i=0;i<n;i++)
  {
   fscanf(f,"%d",&a);fscanf(f,"%d",&b);
   fprintf(g,"%d\n",euclid(a,b));
  }
 fclose(f);
  //fclose(g);
   return 0;
}
