#include <cstdio>
#include <vector>
using namespace std;
int x[1025],y[1025];
int dp[1025][1025];
int lung_cmlsc;
int lcs[1025];
void cmlsc(int x[], int y[])
{
    for(int i=1;i<=x[0];++i)
        for(int j=1;j<=y[0];++j)
        {
            if(x[i]==y[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    for(int i=x[0],j=y[0];i&&j;)
        if(x[i]==y[j])
            lcs[++lung_cmlsc]=x[i],--i,--j;
        else if(dp[i][j-1]>dp[i-1][j])
            --j;
        else
            --i;
}
void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&x[0],&y[0]);
    for(int i=1;i<=x[0];++i)
        scanf("%d",&x[i]);
    for(int i=1;i<=y[0];++i)
        scanf("%d",&y[i]);
    cmlsc(x,y);
    freopen("cmlsc.out","w",stdout);
        printf("%d\n",lung_cmlsc);
    for(int i=lung_cmlsc;i>=1;--i)
        printf("%d ",lcs[i]);
}
int main()
{
    citire();
    return 0;
}
