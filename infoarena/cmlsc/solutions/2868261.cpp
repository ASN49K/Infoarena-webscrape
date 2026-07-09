#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1050], b[1050], dp[1050][1050];


int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];

    for(int i = 1; i <= m; i++)
        fin >> b[i];

    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            if(a[i] == b[j])
                dp[i][j] = dp[i+1][j+1] + 1;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    fout << dp[1][1] << "\n";
    int i = 1, j = 1;
    while(i <= n && j <= m)
        if(a[i] == b[j])
        {
            fout << a[i] << " ";
            i++;
            j++;
        }
        else if(dp[i+1][j] > dp[i][j+1])
            i++;
        else
            j++;
    fout.close();

    return 0;
}
