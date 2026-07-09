#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
int n,m;
int a[1025],b[1025];
stack <int> solution;
void read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
}
bool is_ok(int i, int j)
{
    return (i>0 && j>0)?true:false;
}
void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    int i=n,j=m;
    while(1)
    {
        if(!is_ok(i,j))
            break;
        if(!dp[i][j])
            break;
        if(a[i]==b[j])
        {
            solution.push(a[i]);
            i--, j--;
            continue;
        }
        if(dp[i][j]==dp[i-1][j])
        {
            i--;
            continue;
        }
        j--;
    }
}
void print()
{
    fout<<dp[n][m]<<"\n";
    while(!solution.empty())
    {
        fout<<solution.top()<<" ";
        solution.pop();
    }
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
