#include <stdio.h>

int a[1025];
int b[1025];
int c[1025][1025];
int sol[1025];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    FILE *f;
    int n,m,i,j,lg;

    f=fopen("cmlsc.in","r");
    fscanf(f,"%d%d",&n,&m);
    for (i=1; i<=n; i++)
        fscanf(f,"%d",&a[i]);
    for (i=1; i<=m; i++)
        fscanf(f,"%d",&b[i]);
    fclose(f);

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i] == b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);

    lg=0;
    i=n;
    j=m;
    while (i)
    {
        if (a[i]==b[j])
        {
            sol[++lg]=a[i];
            i--;
            j--;
        }
        else
            if (c[i-1][j] < c[i][j-1])
                j--;
            else
                i--;
    }

    f=fopen("cmlsc.out","w");
    fprintf(f,"%d\n",lg);
    for (i=lg; i>0; i--)
        fprintf(f,"%d ",sol[i]);
    fclose(f);
}
