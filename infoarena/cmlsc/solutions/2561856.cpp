#include <bits/stdc++.h>

#define input "cmlsc.in"
#define output "cmlsc.out"
#define lmax (1<<11)

using namespace std;



int n, m, a[lmax], b[lmax];
int d[lmax][lmax];

main()
{
    ifstream cin(input);
    ofstream cout(output);
    cin >> n >> m;
    for (size_t i = 1; i <= n; ++i)
        cin >> a[i];
    for (size_t i = 1; i <= m; ++i)
        cin >> b[i];
    for (size_t i = 1; i <= n; ++i)
        for (size_t j = 1; j <= m; ++j)
             if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
               else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    cout << d[n][m] << "\n";
    int i = n, j = m;

    vector <int> cd;

    while (i)
    {
        if (a[i] == b[j])
        {
            cd.push_back(a[i]);
            --i;
            --j;
        }
        else if (d[i - 1][j] < d[i][j - 1])
            --j;
        else --i;
    }

    reverse(begin(cd), end(cd));

    for (auto x : cd)
        cout << x << " ";
}
