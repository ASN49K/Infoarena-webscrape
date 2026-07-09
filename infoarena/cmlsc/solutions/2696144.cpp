#include <iostream>

using namespace std;

//ifstream in("");
//ofstream out("");
constexpr int N = 1024+1;
int v1[N],v2[N],dp[N][N];
///dp[i][j] = lungimea maxima a unui subsir comun al prefixelor de lungime i din v1 si j din v2

void afisare(int i,int j,int lung)
{
    if(lung==0)
        return;
    for(i;i>0;--i)
    {
        for(j;j>0;--j)
        {
            if(dp[i][j]==dp[i-1][j-1]+1)
            {
                afisare(i-1,j-1,lung-1);
                cout<<v2[j]<<' ';
                return;
            }
        }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v1[i];
    for(int i=1;i<=m;++i)
        cin>>v2[i];
    int imax,jmax;
    for(int i =1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(v1[i]==v2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                imax = i;
                jmax=j;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[imax][jmax]<<'\n';
    afisare(imax,jmax,dp[imax][jmax]);
    return 0;
}
