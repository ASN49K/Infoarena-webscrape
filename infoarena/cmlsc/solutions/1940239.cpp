#include <iostream>
#include <cstdio>

using namespace std;
int m,n,i,j,k,a[1050],b[1050],x[1050],mat[1050][1050];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (i=1; i<=m; i++)
        scanf("%d",&a[i]);
    for (j=1; j<=n; j++)
        scanf("%d",&b[j]);

    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        if (a[i]==b[j])
        mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    i=m; j=n; k=0;
    while (mat[i][j]>=1)
        if (a[i]==b[j])
        {
            x[++k]=a[i];
            i--;
            j--;
        }
        else
            if (mat[i][j-1]>mat[i-1][j]) j--;
                else i--;
    printf("%d\n",k);
    for (i=k; i>=1; i--)
        printf("%d ",x[i]);
    printf("\n");
    return 0;
}
