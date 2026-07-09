#include <bits/stdc++.h>
using namespace std;

fstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, x, mn, sum, d[1025][1025];
vector<int> a, b;

int main()
{
    f>>n>>m;

    while(n--)
        f>>x, a.push_back(x);

    while(m--)
        f>>x, b.push_back(x);

    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b.size(); ++j)
            if(a[i] == b[j])
                ++d[i][j] += i > 0 && j > 0 ? d[i - 1][j - 1] : 0;
            else
                d[i][j] = max(i > 0 ? d[i - 1][j] : 0, j > 0 ? d[i][j - 1] : 0);


    g << d[a.size() - 1][b.size() - 1] << '\n';

    int cnt = 1;
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b.size(); ++j)
            if(a[i] == b[j] && d[i][j] == cnt)
                g << a[i] << ' ', ++cnt;

    return 0;
}
