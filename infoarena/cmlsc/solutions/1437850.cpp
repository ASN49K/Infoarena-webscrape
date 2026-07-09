#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define N 1030

short v1[N], v2[N], a[N][N], ant[N], rez[N];
int u, nr = 0;
int n, m;

inline bool maxim(int x, int y)
{
    return (x > y) ? x : y;
}

int main()
{
    in >> n >> m;

    for(int i = 1; i <= n; i++)
        in >> v1[i];
    for(int i = 1; i <= m; i++)
        in >> v2[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(v1[i] == v2[j])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
                ant[i] = u;
                u = i;
            }
            else
                a[i][j] = maxim(a[i - 1][j], a[i][j - 1]);

    out << a[n][m] << '\n';

    /*
    while(u)
    {
        rez[++nr] = v1[u];
        u = ant[u];
    }
    for(int i = nr; i >= 1; i--)
        out << rez[i] << ' ';
    out << '\n';*/
    return 0;
}
