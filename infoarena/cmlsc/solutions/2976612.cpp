
#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

// #define f cin
// #define g cout

int n, m, a[1025], b[1025], d[1025][1025];
vector<int> rez;

int main(void)
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);

    for (int i = n, j = m; i;)
        if (a[i] == b[j])
            rez.push_back(a[i]), i--, j--;
        else if (d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    reverse(rez.begin(), rez.end());

    g << rez.size() << '\n';
    for (auto x : rez)
        g << x << " ";

    return 0;
}