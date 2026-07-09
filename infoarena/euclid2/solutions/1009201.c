#include <stdlib.h>
#include <stdio.h>

int algeuclid(int a,int b)
{
    int t;
    if (b==0) return a;
    else 
    {
         t=b;
         b=a%b;
         a=t;
         return algeuclid(a,b);
    }
}

int main()
{
    int i,n,a,b;
    FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for (i=0;i<n;i++)
       {
           fscanf(f,"%d%d",&a,&b);   
           fprintf(g,"%d",algeuclid(a,b));     
       }
    return 0;   
}
