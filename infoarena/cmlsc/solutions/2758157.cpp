#include<fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int const N = 10000;
long long x[N], y[N], a[N][N], v[N];
int k;

void afis(int n, int m)
{
    if (n == 0 || m == 0)
    {
        return;
    }
    if (x[n] == y[m])
    {
        afis(n - 1, m - 1);
        out << x[n] << ' ';
    }
    else if (a[n - 1][m] > a[n][m - 1])
    {
        afis(n - 1, m);
    }
    else
    {
        afis(n, m - 1);
    }
}

int main()
{
    int m, n;
    in >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        in >> x[i];
    }
    for(int i = 1; i <= m; i++)
    {
        in >> y[i];
    }
    in.close();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i] == y[j])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else
            {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    out << a[n][m] << '\n';
    k = a[n][m];
    afis(n, m);
    out.close();
    return 0;
}
