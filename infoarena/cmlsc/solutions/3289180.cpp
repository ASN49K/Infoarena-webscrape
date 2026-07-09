#include <bits/stdc++.h>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int n, m, i, j, p[300], x, mx, s[1030], v[1030], poz, mxt, last[1030], pozl;
queue <int> q;
int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    in >> n >> m;
    for (i = 1; i <= n; ++i)
    {
        in >> x;
        p[x] = i;
        v[i] = x;
    }
    for (i = 1; i <= m; ++i)
    {
        in >> x;
        for (j = 1, mx = 0; j < p[x]; ++j)
            if (s[j] > mx)
                mx = s[j], poz = j;
        for (j = poz; j <= p[x]; ++j)
            if (v[j] == x)
            {
                s[j] = mx + 1;
                if (s[j] > mxt)
                    mxt = s[j], pozl = j;
                last[j] = poz;
            }
    }
    out << mxt << '\n';
    i = pozl;
    while (last[i])
        q.push (v[i]), i = last[i];
    out << v[i] << ' ';
    while (!q.empty())
        out << q.front() << ' ', q.pop();
}
