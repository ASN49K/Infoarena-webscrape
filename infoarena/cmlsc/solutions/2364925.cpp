#include <bits/stdc++.h>

using namespace std;

int n, m, v1[1105], v2[1105], v[1105][1105];

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> v1[i];
    for (int i = 1; i <= m; ++i)
        fin >> v2[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(v1[i] == v2[j])
                v[i][j] = v[i-1][j-1]+1;
            else v[i][j] = max(v[i-1][j], v[i][j-1]);
    fout << v[n][m] << "\n";
    int a = n, b = m;
    vector<int> sol;
    while(a && b)
        if(v1[a] == v2[b])
            sol.push_back(v1[a]), --a, --b;
        else if(v[a-1][b] > v[a][b-1])
            --a;
        else --b;
    reverse(sol.begin(), sol.end());
    for (auto x : sol)
        fout << x << " ";
    return 0;
}
