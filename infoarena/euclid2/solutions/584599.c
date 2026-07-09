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
  fscanf(f,"%d",&n);
  for(i=0;i<n;i++)
  {
    fscanf(f,"%d %d",&a,&b);
    fprintf(g,"%d",euclid(a,b));
  }
    printf("Hello world!\n");
    return 0;
}
