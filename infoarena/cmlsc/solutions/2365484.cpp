#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1001], b[1001], S[1001][1001], Sol[1001], n, m, k;
void LCS()
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
    {
        if(a[i] == b[j]) S[i][j] = 1 + S[i - 1][j - 1];
        else S[i][j] = max(S[i - 1][j], S[i][j - 1]);
    }
}
int main()
{
    in >> n >> m;
    for(int i = 1;i <= n;i++)
        in >> a[i];
    for(int i = 1;i <= m;i++)
        in >> b[i];
    LCS();
    int i = n, j = m;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            Sol[++k] = a[i];
            i--;
            j--;
        }
        else if(S[i - 1][j] < S[i][j - 1]) j--;
        else i--;
    }
    out << k << '\n';
    for(int i = k;i >= 1;i--)
        out << Sol[i] << " ";
    return 0;
}
