#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1025
using namespace std;

vector <int> a,b,sol;
int n,m,dp[N][N];

void Read()
{
    int i,x;
    freopen("cmlsc.in","r",stdin);
    a.push_back(0);b.push_back(0);

    scanf("%d%d",&n,&m);

    for (i=1;i<=n;++i)
    {
        scanf("%d",&x);
        a.push_back(x);
    }

    for (i=1;i<=m;++i)
    {
        scanf("%d",&x);
        b.push_back(x);
    }

}

void Dinamic()
{
    int i,j;

    for (i=0;i<=n;++i)
        for (j=0;j<=m;++j)
            if (i==0 || j==0) dp[i][j]=0;
            else if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    i=n;j=m;

    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i][j]==dp[i-1][j]) i--;
             else j--;
    }
}

void Write()
{
    int i;
    freopen("cmlsc.out","w",stdout);

    printf("%d\n",sol.size());

    for (i=sol.size()-1;i>=0;--i)
        printf("%d ",sol[i]);
}
int main()
{
    Read();
    Dinamic();
    Write();
    return 0;
}
