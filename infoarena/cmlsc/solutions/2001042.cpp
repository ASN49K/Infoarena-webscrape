#include <cstdio>
#include <vector>
#define MAX 1030
using namespace std;

int dp[MAX][MAX],a[MAX],b[MAX],m,n;
vector <int> sir;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i=1; i<=m; i++)
        scanf("%d",&a[i]);
    for (int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if (a[i]==b[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    int i=m,j=n;
    while (i)
    {
        if (a[i]==b[j])
        {
            sir.push_back(a[i]);
            i--;
            j--;
        }
        ///vedem ce e mai optim sa scadem: i sau j
        else if (dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    printf("%d\n",dp[m][n]);
    for (int i=dp[m][n]-1; i>=0; i--)
        printf("%d ",sir[i]);
    return 0;
}
