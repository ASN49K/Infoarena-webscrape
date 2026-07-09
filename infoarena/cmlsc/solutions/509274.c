#include <stdio.h>
#include <stdlib.h>
FILE *f,*g;
int m,n,a[1024],b[1024],c[1024][1024],i,j,nrel,d[1024];
int maxim(int a,int b)
{
    if(a>b)
       return a;
    return b;
}
int main()
{
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d%d",&m,&n);
    for(i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
          if(a[i]==b[j])
             c[i][j]=1+c[i-1][j-1];
          else
             c[i][j]=maxim(c[i-1][j],c[i][j-1]);
    j=n;
    i=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            d[++nrel]=a[i];
            i--;
            j--;
        }
        else
           if(c[i-1][j]<c[i][j-1])
               j--;
           else
              i--;
    }
    for(i=nrel;i>0;i--)
       fprintf(g,"%d ",d[i]);
    fclose(f);
    fclose(g);
    return 0;
}
