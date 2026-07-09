#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030], b[1030], dp[1030];
int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int i = 1; i <= m; ++i)
        fin >> b[i];
    for(int i = 1; i <= n; ++i)
    {
        int cop = a[i];
        for(int j = 1; j <= m; ++j)
        {
            if(cop == b[j])
            {
                dp[j]++;
                cop = -1;
            }
            dp[j] = max(dp[j], dp[j-1]);
        }
    }
    fout << dp[m] << "\n";
    int cnt = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j] && cnt == dp[j])
            {
                fout << a[i] << " ";
                cnt++;
                break;
            }
        }
    }
    fout << "\n";
    return 0;
}