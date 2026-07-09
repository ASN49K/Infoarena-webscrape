#include <iostream>
#include <stdio.h>

using namespace std;

int m,n,a[1035],b[1035];
int mat[1035][1035];

void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d",&m,&n);
    for(int i=1; i<=m; i++)
        scanf("%d ",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d ",&b[i]);
}

void cmlsc()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            int v=0;
            if(a[i]==b[j])
                v=1;
            mat[i][j]=max(max(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1]+v);
        }
        printf("%d\n",mat[m][n]);
}

void bt()
{
    int i=m,j=n;
    int d[1035],u=0;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            d[u++]=a[i];
            i--;
            j--;        }
        else
            if(mat[i-1][j]>mat[i][j-1])
                i--;
        else
                j--;

    }

    for(int i=u-1;i>=0;i--)
        printf("%d ",d[i]);
}


int main()
{
    freopen("cmlsc.out","w",stdout);
    citire();
    cmlsc();
    bt();
    return 0;
}
