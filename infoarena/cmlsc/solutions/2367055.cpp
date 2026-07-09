#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, x, cmlsc[1027][1027], t[1027];
vector<int> a, b;

int main()
{
    f >> m >> n;
    
    // index from 1
    a.push_back(0);
    b.push_back(0);

    while (m--) f >> x, a.push_back(x);
    while (n--) f >> x, b.push_back(x);

    for (int i = 1; i < a.size(); ++i)
        for (int j = 1; j < b.size(); ++j)
            if (a[i] == b[j])
                cmlsc[i][j] += cmlsc[i - 1][j - 1] + 1;
            else
                cmlsc[i][j] = max(cmlsc[i - 1][j], cmlsc[i][j - 1]);

    g << cmlsc[a.size() - 1][b.size() - 1] << '\n';
    
    int cnt = 1;
    for (int j = 0; j < b.size(); ++j)
        if (cmlsc[a.size() - 1][j] == cnt)
            g << b[j] << ' ',
            ++cnt;

    return 0;
}

