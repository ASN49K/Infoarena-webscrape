#include <bits/stdc++.h>

#define NMax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M;
int a[NMax],b[NMax];
int dp[NMax][NMax];
stack<int> sol;

int main()
{
    fin>>M>>N;
    for(int i=1;i<=M;i++)
        fin>>a[i];
    for(int i=1;i<=N;i++)
        fin>>b[i];

    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    for(int i=M,j=N;i&&j;)
    {
        if(a[i]==b[j])
            sol.push(a[i]), i--, j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }

    fout<<sol.size()<<"\n";
    for(;!sol.empty();sol.pop())
        fout<<sol.top()<<" ";

    return 0;
}
