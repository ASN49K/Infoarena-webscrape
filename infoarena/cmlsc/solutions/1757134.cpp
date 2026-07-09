#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define endl "\n"
#include <stdio.h>
using namespace std;
    int matrix[1050][1050],a[1050],b[1050];
    int n,m,ans[2000],k = 0;
    bool shown = false;
void LCA()
{
    for(int i=1;i<=n;i++)
        matrix[i][0] = 0;
    for(int j=1;j<=m;j++)
        matrix[0][j] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if (a[i] == b[j])
            matrix[i][j] = matrix[i-1][j-1] + 1;
        else matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j]);
}

void build(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (a[i] == b[j])
    {
        ans[++k] = a[i];
        build(i-1, j-1);
    } else
          if (matrix[i][j-1] > matrix[i-1][j])
            build(i, j-1);
            else build(i-1, j);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    //freopen("cmlsc.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
        cin >> b[i];
    //cout << n << ' ' << m;
    LCA();
    int x = matrix[n][m];
    cout << x << "\n";
    build(n,m);
    for(int i=k; i>0; i--)
        cout << ans[i] << ' ';
    return (0);
}
