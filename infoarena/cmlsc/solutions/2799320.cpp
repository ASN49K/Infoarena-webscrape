#include <bits/stdc++.h>

using namespace std;

int a[1030],b[1030],dp[1030][1030],ans[1030];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int na,nb,inda,indb,cnt = 0;
    fin >> na >> nb;
    for (int i = 1;i <= na;i++)
        fin >> a[i];
    for (int i = 1;i <= nb;i++)
        fin >> b[i];
    for (int i = 1;i <= na;i++) {
        for (int j = 1;j <= nb;j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    inda = na;
    indb = nb;
    while (inda) {
        if (a[inda] == b[indb]) {
            ans[cnt++] = a[inda];
            inda--;
            indb--;
        }
        else if (dp[inda - 1][indb] < dp[inda][indb - 1])
            indb--;
        else
            inda--;
    }
    fout << cnt << '\n';
    for (int i = cnt - 1;i >= 0;i--)
        fout << ans[i] << " ";
    return 0;
}
