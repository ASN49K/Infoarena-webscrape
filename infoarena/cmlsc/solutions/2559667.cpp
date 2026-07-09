#include <bits/stdc++.h>

using namespace std;

#define ll int
#define INF 1234567890
#define N (int)(2e5 + 5)

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int matrix[1050][1050];
void solve()
{
    int t[1050], v[1050];
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> t[i];
    for(int i = 1; i <= m; ++i) fin >> v[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        if(t[i] == v[j]) matrix[i][j] = matrix[i - 1][j - 1] + 1;else
        matrix[i][j] = max(matrix[i - 1][j], matrix[i][j -  1]);
    fout << matrix[n][m] << "\n";
    int i = n, j = m;
    vector <int> elem;
    while(matrix[i][j])
        if(t[i] == v[j]) elem.push_back(t[i]), --i, --j;else
        if(matrix[i - 1][j] == matrix[i][j]) --i;else --j;
        reverse(elem.begin(), elem.end());
        for(int i = 0; i < matrix[n][m]; ++i) fout << elem[i] << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    fin.tie(0);
    solve();
    return 0;
}
