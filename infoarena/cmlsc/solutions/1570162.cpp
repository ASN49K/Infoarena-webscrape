#include <cstdio>
#include <algorithm>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

using namespace std;

int a[1025],b[1025],c[1025][1025],m,n,i;

void solve()
{
    int i,j;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
}

void afis(int i, int j)
{
    if (i>=1 && j>=1)
        if (a[i]!=b[j])
            if (c[i][j-1]>c[i-1][j]) afis(i,j-1);
            else afis (i-1,j);
        else
        {
            afis(i-1,j-1);
            fprintf(g,"%d ",a[i]);
        }
}

int main()
{
    fscanf(f,"%d%d",&m,&n);
    for (i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for (i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);
    solve();
    fprintf(g,"%d\n",c[m][n]);
    afis(m,n);
    fclose(f);
    fclose(g);
    return 0;
}
