#include <cstdio>
#include <iostream>
using namespace std;


int dp[1025][1025],p[1025];


void Citire (int a[1025],int b[1025],int &n, int &m)
{
    freopen ("cmlsc.in","r",stdin);
    scanf ("%d",&n);
    scanf ("%d",&m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d",&b[i]);
    }
}

void Construire (int a[1025],int b[1025],int n, int m)
{
    int k=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
                p[k++]=a[i];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

}

int main()
{
    freopen ("cmlsc.out","w",stdout);
    int a[1025]= {0},b[1025]= {0},n,m;
    Citire(a,b,n,m);
    Construire(a,b,n,m);
    printf("%d\n",dp[n][m]);
    for (int i=0;i<dp[n][m];i++)
        printf("%d ",p[i]);
    return 0;
}
