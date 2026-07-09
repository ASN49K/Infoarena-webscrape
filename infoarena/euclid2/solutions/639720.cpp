#include <stdlib.h>
#include <stdio.h>

int cmmdc(int a,int b)
{
    int t;
    if(b==0)
    return a;
    while(b)
    {
       t=b;
       b=a%b;
       a=t;
    }      
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
                    
      fscanf(f,"%d%d",&a,&b);
      fprintf(g,"%d\n",cmmdc(a,b));
        
    }

    fclose(f);
    return 0;
}
           
