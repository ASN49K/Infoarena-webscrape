#include <stdio.h>


int m,n,p,a[1026],b[1026],c[1026],u[1026];

int main()
{
    int i,j,aux,aux1;
    FILE *f,*g;

    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");

    fscanf(f,"%d%d",&m,&n);

    for(i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);

    u[0]=-1;
    for(i=1;i<=m;i++)
    {
        aux=0;
        for(j=1;j<=n;j++)
        {
            aux1=c[j];
            if(a[i]==b[j])
            {
                 c[j]=aux+1;
                 u[j]=b[j];
            }
            else
            {
                if(c[j-1]>c[j])
                {
                   c[j]=c[j-1];
                   u[j]=u[j-1];
                }
            }
            aux=aux1;
        }
    }
    fprintf(g,"%d\n",c[n]);
    for(j=1;j<=n;j++)
    {
        if(u[j]!=u[j-1])
            fprintf(g,"%d ",u[j]);
    }
    fclose(f);
    fclose(g);
}
