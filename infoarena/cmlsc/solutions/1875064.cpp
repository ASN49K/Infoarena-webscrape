#include <stdio.h>
#define maxn 1026

short n,m,i,j,q;
short a[maxn],b[maxn],d[maxn][maxn],sol[maxn];

short max(short a, short b,short c)
{
    if(a>b && a>c)
        return a;
    if(b>c)
        return b;
    return c;
}

int main()
{
    FILE *f1,*f2;
    f1=fopen("cmlsc.in","r");
    f2=fopen("cmlsc.out","w");

    fscanf(f1,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f1,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(f1,"%d",&b[i]);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=max(d[i-1][j-1]+1,d[i-1][j],d[i][j-1]);
            else
                d[i][j]=max(d[i-1][j],d[i][j-1],-1);
    }

    fprintf(f2,"%d\n",d[n][m]);

    i=n;j=m;
    while(d[i][j])
    {
        if(d[i][j]==d[i-1][j-1]+1 && a[i]==b[j])
        {
            sol[++q]=a[i];
            i--;
            j--;
        }
        else if(d[i][j]==d[i-1][j])
            i--;
        else
            j--;
    }

    while(q)
        fprintf(f2,"%d ",sol[q--]);

    return 0;
}
