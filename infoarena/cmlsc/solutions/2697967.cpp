#include<bits/stdc++.h>

using namespace std;

int d[1030][1030], a[1030], b[1030];
vector<int> ans;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j]) d[i][j] = 1 + d[i - 1][j - 1];
            else d[i][j] = max(d[i][j - 1], d[i - 1][j]);
    printf("%d\n", d[n][m]);
    for(int i = n; i > 0 and d[n][m];)
        for(int j = m; j > 0 and d[n][m];)
            if(a[i] == b[j]) ans.push_back(a[i]), i--, j--, d[n][m]--;
            else if(d[i][j - 1] < d[i - 1][j]) i--;
            else j--;
    for(int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
	return 0;
}
