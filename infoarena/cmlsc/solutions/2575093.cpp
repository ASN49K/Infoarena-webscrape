#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, a[10001], b[10001], dp[10001][10001], S[10001];
int k;
void cmlsc(int a[], int b[])
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}
int main()
{
    in >> n >> m;
    for(int i = 1;i <= n;i++)
        in >> a[i];
    for(int i = 1;i <= m;i++)
        in >> b[i];
    cmlsc(a, b);
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            S[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }
    out << k << '\n';
    for(int i = k;i >= 1;i--)
        out << S[i] << " ";
    return 0;
}
