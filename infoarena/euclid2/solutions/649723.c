#include<stdio.h>
int alg_euclid(int a,int b)
{
    if(!b)
     return a;
  return alg_euclid(b,a%b);
}     
int main()
{
    int a,b,n,i;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
   g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for (;n;--n)
    {
      fscanf(f,"%d %d",&a,&b);
      fprintf(g,"%d \n",alg_euclid(a,b));
      
      }
fclose(f);
fclose(g);
return 0;
}          
