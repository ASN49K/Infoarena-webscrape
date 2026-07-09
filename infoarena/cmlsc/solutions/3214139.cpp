#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,v1[1028],v2[1028],dp[1028][1028];
stack<int>q;


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
    fout<<dp[n][m]<<endl;
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
        fout<<q.top()<<' ';
        q.pop();
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v1[i];
    for(int i=1; i<=m; i++)
        fin>>v2[i];
    idk();
    afisare();
    return 0;
}