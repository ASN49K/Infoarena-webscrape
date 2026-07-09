#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX=1025;

int N, M, a[NMAX], b[NMAX], dp[NMAX][NMAX], sol[NMAX], num;

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
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    fout<<dp[M][N]<<'\n';

    num=dp[M][N];
    for(int i=M,j=N;i>=1 and j>=1;){
        if(a[i]==b[j]){
            sol[num--]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }

    for(int i=1;i<=dp[M][N];i++)
        fout<<sol[i]<<' ';

    fin.close();
    fout.close();

    return 0;
}
