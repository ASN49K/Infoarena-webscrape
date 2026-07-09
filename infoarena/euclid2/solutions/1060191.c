#include <stdio.h>
#include <stdlib.h>

int v[30001],m,x,d,i,n,mx,ok;

int main()
{
    FILE *f, *g;
    f=fopen("exp.in" , "r");
    g=fopen("exp.out" , "w");
    fscanf(f,"%d",&m);
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        for(d=2;x!=1;d++)
        {
            while(x%d==0)
            {
                v[d]++;
                x=x/d;
            }
        }
        if(d>mx)
        mx=d;
    }
    for(i=2;i<=mx;i++)
    {
        if(v[i]!=0 && v[i]%m!=0)
        {
            ok=1;
            i=mx+1;
        }
    }
    if(ok==1)
    {
        fprintf(g,"0\n");
    }
    else
    {
        fprintf(g,"1\n");
        for(i=2;i<=mx;i++)
        {
            if(v[i]!=0)
            {
                fprintf(g,"%d %d",i,v[i]/m);
            }
        }
    }
    return 0;
}
