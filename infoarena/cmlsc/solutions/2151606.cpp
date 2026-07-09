#include <fstream>

using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int n,m;
int a[1030];
int b[1030];
int c[1030];
int dp[1030][1030];
int k;
bool fr[258];


int main()
{
    fi>>n>>m;
    for(int i=1;i<=n;i++)
    fi>>a[i];
    for(int i=1;i<=m;i++)
    fi>>b[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }


//
//    for(int i=1;i<=n;i++)
//        {for(int j=1;j<=m;j++)
//        fo<<dp[i][j]<<" ";
//        fo<<endl;
//        }

    int l=dp[n][m];
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
    {
        if(dp[i][j]==l and a[i]==b[j])
        {

            c[++k]=a[i];
            l--;
        }

    }

        fo<<dp[n][m]<<'\n';
        for(int i=k;i>=1;i--)
            fo<<c[i]<<" ";

    return 0;
}
