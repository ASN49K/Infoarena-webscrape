#include<fstream>
using namespace std;

ifstream f("cmlsc.in"); ofstream g("cmlsc.out");

const int NMAX = 1025;
int n, m, k, x[NMAX], y[NMAX], p[NMAX][NMAX], sol[NMAX];

inline void read_Data()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i) f >> x[i];
    for(int i = 1; i <= m; ++i) f >> y[i];
}

inline void solve()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(x[i] == y[j]) p[i][j] = 1 + p[i - 1][j - 1];
            else
            p[i][j] = max(p[i - 1][j], p[i][j - 1]);
}

inline void write_Data()
{
    g << p[n][m] <<'\n';
    int i = n, j = m;
    while(p[i][j])
    {
        if(x[i] == y[j]) sol[++k] = x[i], --i, --j;
        else
        {
            if(p[i - 1][j] > p[i][j - 1]) --i;
            else --j;
        }
    }
    for(; k > 0; --k) g << sol[k] << ' ';
}

int main()
{
    read_Data();
    solve();
    write_Data();

    g.close();
    return 0;
}
