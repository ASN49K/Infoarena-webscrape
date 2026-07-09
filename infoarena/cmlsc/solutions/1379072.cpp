#include <stdio.h>
#define maxn 1025
int n,m,i,j;
short mat[maxn][maxn],a[maxn],b[maxn];
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
    fscanf(f1,"%d %d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f1,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(f1,"%d",&b[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
            if(a[i]==b[j])mat[i][j]++;
        }
    fprintf(f2,"%d\n",mat[n][m]);
    return 0;
}
