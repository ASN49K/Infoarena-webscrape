#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int s[25000],p,x,sum=0;
void citire()
{
    int i;
    FILE *f=fopen("sume.in","r");
    fscanf(f,"%d",&p);
    for(i=0;i<p;i++)
    {
        fscanf(f,"%d",&s[i]);
        sum+=s[i];
    }
}
void haralambie()
{

   int n=1,k=1,i,s1=0;
   float q,m;
   int *a;
   FILE *g=fopen("sume.out","w");
   m=sqrt(1+8*p);
   if(m!=(int)m)
    fprintf(g,"-1");
    else
    {
    while(n*(n-1)!=2*p)
    n++;
    a=malloc(n*sizeof(int));
    q=(s[0]+s[1]-s[n-1])/2;
    if(q!=(int)q)
        x=-1;
    else
        x=(int)q;
      if(x<0)
        fprintf(g,"-1");
   else
            {
                while(k!=n)
                {
                    a[k-1]=s[k-1]-x;
                    //fprintf(g,"%d ",s[k-1]-x);
                    k++;
                }
                for(i=0;i<k-1;i++)
                s1=s1+a[i];
                s1+=x;
                if((sum%s1)!=0)
                    fprintf(g,"-1");
                else
                    {
                        fprintf(g,"%d\n",n);
                        fprintf(g,"%d ",x);
                        for(i=0;i<k-1;i++)
                            fprintf(g,"%d ",a[i]);
                    }
            }
    }
}
int main()
{
    citire();
    haralambie();
    return 0;
}
