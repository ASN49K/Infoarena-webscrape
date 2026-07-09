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



//    for(int i=1;i<=n;i++)
//        {for(int j=1;j<=m;j++)
//        fo<<dp[i][j]<<" ";
//        fo<<endl;
//        }
    int t=0,x=0;
    for(int i=1;i<=n;i++)
        {
//            if(x==1)
//                break;
        for(int j=1;j<=m;j++)
    {
        if(dp[i][j]==t+1)
        {
            c[++k]=a[i];
            t++;
        }
//        if(t==min(i,j)+1)
//        {break;x=1;}
    }
        }
        fo<<dp[n][m]<<'\n';
        for(int i=1;i<=k;i++)
            fo<<c[i]<<" ";

    return 0;
}
