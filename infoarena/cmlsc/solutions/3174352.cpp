#include <fstream>
#include <queue>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1025][1025],n,m,a[1025],b[1025],lmax=0;
queue <int>s;

void read()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
}
void cmlsc()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(dp[i][j]>lmax)
        {
            lmax=dp[i][j];
            s.push(a[i-1]);
        }
    }

}
void afisare()
{
    cout<<lmax<<'\n';
    while(!s.empty())
    {
        cout<<s.front()<<' ';
        s.pop();
    }
}
int main()
{
    read();
    cmlsc();
    afisare();
    return 0;
}
