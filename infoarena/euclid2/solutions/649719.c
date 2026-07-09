#include<stdio.h>
int cmmdc(int a,int b)
{
    if(b==0)
     return a;
     cmmdc(a,a%b);
}     
int main()
{
    int a,b,n,i;
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for (i=1;i<=n;i++)
    {
      fscanf(f,"%d %d",&a,&b);
      fprintf(g,"%d \n",cmmdc(a,b));
      
      }
fclose(f);
fclose(g);
system("pause");
return 0;
}          
