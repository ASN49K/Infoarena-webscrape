#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");

long long N,K,a[100005],dp[100005];

int main()
{
    fin >> N;
    int i,j;
    for (i=1;i<=N;++i)
    {
        fin >> a[i];
    }
    dp[1]=1;
    for (i=2;i<=N;++i)
    {
        int maxim=0;
        for (j=1;j<=i-1;++j)
        {
            if (a[j]<a[i] && dp[j]>maxim)
            {
                maxim=dp[j];
            }
        }
        dp[i]=1+maxim;
        K=max(K,dp[i]);
    }
    fout << K << '\n';
    return 0;
}
