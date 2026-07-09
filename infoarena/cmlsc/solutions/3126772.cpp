#include <iostream>
#include <fstream>
#include <stack>
#define maxi 1050
using namespace std;
ifstream f;
ofstream g;
stack<int> stiva;
int dp[maxi][maxi],n,m,a[maxi],b[maxi];
void READ()
{
    f.open("cmlsc.in",ios::in);
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    f.close();
    return;
}
inline int maxim(int a,int b)
{
    return(a>b?a:b);
}
void DP()
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=maxim(dp[i-1][j],dp[i][j-1]);
        }
    }
    int is=n;
    int js=m;
    for(;;)
    {
        if(is<=1&&js<=1)
        {
            if(a[is]==b[js]&&is==1&&js==1)
                stiva.push(a[is]);
            break;
        }
        if(a[is]==b[js])
        {
            stiva.push(a[is]);
            is--;
            js--;
        }
        else{
            if(dp[is-1][js]>dp[is][js-1])
            {
                is--;
            }
            else js--;
        }
    }
    return;
}
int main()
{
    g.open("cmlsc.out",ios::out);
    READ();
    DP();
    g<<dp[n][m]<<'\n';
    while(!stiva.empty())
    {
        g<<stiva.top()<<" ";
        stiva.pop();
    }
    g.close();
    return 0;
}