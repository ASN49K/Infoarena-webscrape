/**
*/
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax=1024;
short int x[nmax],y[nmax],n,m;
short int dp[nmax][nmax],v[nmax];
void read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>x[i];
    }

    for(int i=1;i<=m;i++)
    {
        fin>>y[i];
    }

}
void solve()
{
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {

                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
void print()
{

    int i=n,j=m,k=0;
    while(i>0 && j>0)
    {
        if(x[i]==y[j])
        {
            v[++k]=x[i];
            //cout<<x[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j]==dp[i-1][j])
                i--;
            else
                j--;
        }

    }
    fout<<k<<endl;
    for(int i=k;i>=1;i--)
    {
        fout<<v[i]<<" ";
    }
}
int main()
{
    read();
    solve();
    print();
   return 0;
}

