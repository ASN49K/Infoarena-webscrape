#include <fstream>
#include <stack>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,v1[1028],v2[1028],dp[1028][1028];
stack<int>q;

void citire()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>v1[i];
    for(int i=1; i<=m; i++)
        cin>>v2[i];
}
void idk()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v1[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
}
void afisare()
{
    cout<<dp[n][m]<<'\n';
    int i=n,j=m;
    while(dp[i][j])
    {
        if(dp[i][j-1]==dp[i][j])
            j--;
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else
        {
            q.push(v1[i]);
            i--;
            j--;
        }
    }
    while(!q.empty())
    {
        cout<<q.top()<<' ';
        q.pop();
    }
}
int main()
{
    citire();
    idk();
    afisare();
    return 0;
}
