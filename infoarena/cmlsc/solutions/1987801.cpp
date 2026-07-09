#include <fstream>

using namespace std;

ifstream F("cmlsc.in");
ofstream G("cmlsc.out");

int n, m, v[1030], w[1030], d[1030][1030], x, y, k, sol[1030];

int main()
{
    F >> n >> m;
    for(int i = 1; i <= n; ++ i)
        F >> v[i];
    for(int i = 1; i <= m; ++ i)
        F >> w[i];

    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(v[i] == w[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    G << d[n][m] << '\n';
    x = n; y = m;
    while(x && y)
    {
        if(d[x][y] == d[x - 1][y])
            x = x - 1;
        else if(d[x][y] == d[x][y - 1])
            y = y - 1;
        else
            sol[++ k] = v[x], x --, y --;
    }
    for(int i = k; i > 0; -- i)
        G << sol[i] << " ";
    return 0;
}
