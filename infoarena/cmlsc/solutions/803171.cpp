#include <cstdio>
#include<algorithm>
#define N 1025


using namespace std;

int n,m,i,j,k,a[N],b[N],C[N],D[N][N];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i][j-1],D[i-1][j]);
        }
    printf("%d\n",D[n][m]);
    for(i=n,j=m;D[i][j];)
        {
            if(a[i]==b[j])
            {
                k++;
                C[k]=a[i];
                i--;j--;
            }
            else if(D[i-1][j]>D[i][j-1])
                i--;
            else j--;
        }
    for(i=k;i>=1;i--)
        printf("%d ",C[i]);
    return 0;
}
