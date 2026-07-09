#include <iostream>
#include <bits/stdc++.h>
#define VMAX 1100
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int numere[2][VMAX];
int dp[VMAX][VMAX];
vector<int> solutie;

int main()
{
    int n,m,i,j,k,t,q,nr,minim,maxim;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>numere[0][i];
    for(i=1;i<=m;i++)
        fin>>numere[1][i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(numere[0][i]==numere[1][j])
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
        }
    }

    fout<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(dp[i][j])
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            solutie.push_back(numere[0][i]);
            i--;
            j--;
        }
    }

    while(!solutie.empty())
    {
        fout<<solutie.back()<<' ';
        solutie.pop_back();
    }

    return 0;
}
