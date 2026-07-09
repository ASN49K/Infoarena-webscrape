#include <bits/stdc++.h>
using namespace std;

ifstream fin("asmin.in");
ofstream fout("asmin.out");

int n, k;
int r[16005], dp[16005];
vector<int> a[16005];
vector<int> rez;

void Init()
{
    for (int i = 1; i <= n; i++)
        dp[i] = 0;
}

void DFS1(int x, int t)
{
    dp[1] += (r[x] - r[t] + k) % k;
    for (int e : a[x])
        if (e != t)
            DFS1(e, x);
}

void DFS2(int x, int t)
{
    if (t != 0)
        dp[x] = dp[t] - r[t] - (r[x] - r[t] + k) % k + r[x] + (r[t] - r[x] + k) % k;;
    for (int e : a[x])
        if (e != t)
            DFS2(e, x);
}

int main()
{
    int x, y, sol;
    fin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        fin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        fin >> r[i];
    DFS1(1, 0);
    DFS2(1, 0);
    sol = INT_MAX;
    for (int i = 1; i <= n; i++)
        if (sol > dp[i])
        {
            sol = dp[i];
            rez.clear();
            rez.push_back(i);
        }
        else if (sol == dp[i])
            rez.push_back(i);
    fout << sol << " " << rez.size() << "\n";
    for (int i : rez)
        fout << i << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}
/**

r = 1
v1 = 0; v2 = 1; v3 = 2; v4 = 0; v5 = 2; C = 5;

r = 2
v1 = 2; v2 = 1; v3 = 2; v4 = 0; v5 = 2; C = 7;

r = 3
v1 = 1; v2 = 1; v3 = 2; v4 = 0; v5 = 2; C = 6;

r = 4
v1 = 2; v2 = 0; v3 = 2; v4 = 1; v5 = 2; C = 7;

r = 5
v1 = 2; v2 = 1; v3 = 2; v4 = 0; v5 = 0; C = 5;
*/
