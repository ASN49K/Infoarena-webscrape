#include<fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int const N = 100;
int x[N], y[N], a[N][N], v[N];
int m, n;

void dinamic()
{
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
}

int main()
{
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
    dinamic();
    int k = a[n][m];
    for (int i = 1; i <= n && k > 0; i++)
    {
        for (int j = 1; j <= n && k > 0; j++)
        {
            if (x[i] == y[j])
            {
                k--;
                out << x[i] << ' ';
            }
        }
    }
    out.close();
    return 0;
}
