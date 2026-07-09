#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[1025], b[1025], c[1025][1025];

void afis(int x, int y)
{
    if(!x || !y)
        return ;

    if(c[x][y] == c[x - 1][y - 1] + 1)
    {
        afis(x - 1, y - 1);
        g << a[x] << " ";
    }

    else if(c[x][y] == c[x - 1][y])
        afis(x - 1, y);
    else
        afis(x, y - 1);
}

int main()
{
    f >> n >> m;

    for(int i = 1; i <= n; i ++)
        f >> a[i];

    for(int j = 1; j <= m; j ++)
        f >> b[j];

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);

    g << c[n][m] << '\n';
    afis(n, m);
    return 0;
}
