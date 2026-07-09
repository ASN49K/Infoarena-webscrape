#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,d[1030][1030],a[1030],b[1030];

int main()
{
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int i = 1; i <= m; i++)
        in >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j],d[i][j - 1]);
        }
    int i = n,j = m;
    vector<int>v;
    while (i > 0)
    {
        if (a[i] == b[j])
        {
            v.push_back(a[i]);
            i--;
            j--;
        }
        else if (d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    }
    reverse(v.begin(),v.end());
    out << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
        out << v[i] << ' ';
    return 0;
}
