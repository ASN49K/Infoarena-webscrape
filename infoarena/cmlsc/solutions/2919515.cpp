#include <bits/stdc++.h>

#define Nmax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[Nmax], b[Nmax];
int N, M;
int dp[Nmax][Nmax];
vector<int>sol;
int L = 0;

int main()
{
    fin>>N>>M;
    for(int i=1;i<=N;i++) fin>>a[i];
    for(int i=1;i<=M;i++) fin>>b[i];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    for(int i = N, j = M; i >= 1 && j >= 1;)
    {
        if(a[i] == b[j])
            sol.push_back(a[i]), i--, j--;
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(sol.begin(),sol.end());
    fout<<sol.size()<<"\n";
    for(auto x:sol) fout<<x<< " ";
    return 0;
}
