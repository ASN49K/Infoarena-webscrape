#include <stdio.h>
#define maxn 1025
int n,m,i,j,q;
short mat[maxn][maxn],a[maxn],b[maxn],v[maxn];
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    FILE*f1,*f2;
    f1=fopen("cmlsc.in","r");
    f2=fopen("cmlsc.out","w");
    fscanf(f1,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f1,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(f1,"%d",&b[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    fprintf(f2,"%d\n",mat[n][m]);
    i=n;j=m;
    while(mat[i][j])
        if(a[i]==b[j])
        {
            v[q++]=a[i];
            --i;--j;
        }
        else
        {
            if(mat[i][j-1]>mat[i-1][j])
                j--;
            else i--;
        }
    for(i=q-1;i>=0;i--)
        fprintf(f2,"%d ",v[i]);
    return 0;
}
