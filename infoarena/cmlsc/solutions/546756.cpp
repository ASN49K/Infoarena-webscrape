#include <stdio.h>
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int i,j,n,m,a[1025],b[1025],p[1025][1025],max,sol[1026];
int main(void)
{
    fscanf(f,"%d%d",&n,&m);
    for (i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for (j=1;j<=m;j++)
        fscanf(f,"%d",&b[j]);
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
                if (p[i][j-1]>p[i-1][j])
                    max=p[i][j-1];
                else max=p[i-1][j];
                if (a[i]==b[j]) p[i][j]=1+p[i-1][j-1];
                else p[i][j]=max;
        }
    fprintf(g,"%d\n",p[n][m]);
    i=n;
    j=m;
    while (i && j)
    {
        if (a[i]==b[j])
        {
            sol[++sol[0]]=a[i];
            i--;
            j--;
        }
        else
        {
            if (p[i-1][j]>p[i][j-1])
                i--;
            else j--;
        }
    }
    for (i=sol[0];i>=1;i--)
        fprintf(g,"%d ",sol[i]);
    fclose(g);
    return 0;
}