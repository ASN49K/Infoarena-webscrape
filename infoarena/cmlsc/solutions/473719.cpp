#include <stdio.h>

using namespace std;
int a[1024],b[1024],sol[1024],nr,m,n,mat[1024][1024];

int max(int w,int v)
{
    if(w>v)return w;
    else return v;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int i,j;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else mat[i][j]=max(mat[i][j-1],mat[i-1][j]);

    for(i=n,j=m;i && j;)
        if(a[i]==b[j])
        {
            sol[++nr]=a[i];
            i--;j--;
        }
        else if(mat[i-1][j]>mat[i][j-1])i--;
            else j--;

    printf("%d\n",nr);
    for(i=nr;i>0;i--)printf("%d ",sol[i]);

    return 0;
}
