#include <stdlib.h>
#include <stdio.h>

int cmmdc(int a,int b)
{
    if(a==0)
    return b;
    while(b!=0)
    if(a>b)
    a=a-b;
    else
    b=b-a;
    return a;
}

int main()
{
   
    unsigned int T,a,b,i;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
  
    fscanf(f,"%d",&T);
    
    for(i=1;i<=T;i++)
    {             
      fscanf(f,"%d",&a);
       fscanf(f,"%d",&b);
      fprintf(g,"%d\n",cmmdc(a,b));  
    }

    fclose(f);
    return 0;
}
           
