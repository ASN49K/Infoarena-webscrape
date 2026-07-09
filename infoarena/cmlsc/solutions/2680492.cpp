#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int n, m, v[1205], x[1205], s[1205][1205], ts[1205];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    for(int i = 1; i <= m; ++i)
    {
        cin >> x[i];
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(v[i] == x[j])
                s[i][j] = s[i - 1][j - 1] + 1;
            else
                s[i][j] = max(s[i - 1][j], s[i][j - 1]);
        }

    for(int i = n, j = m; i > 0 && j > 0;)
    {
        if(v[i] == x[j])
            ts[++ts[0]] = v[i], --i, --j;
        else if(s[i - 1][j] > s[i][j - 1])
            --i;
        else
            --j;
    }

    cout << s[n][m] << '\n';

    for(int i = ts[0]; i > 0; --i)
        cout << ts[i] << ' ';

    return 0;
}
