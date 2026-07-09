#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, a[1025], b[1025], Max[1025], d[1025][1025], k;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                d[i][j] = 1 + d[i - 1][j - 1];
            }
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    int i = n, j = m;
    while (i && j)
    {
        if(a[i] == b[j])
        {
            Max[++k] = a[i];
            i--;
            j--;
        }
        else if (d[i - 1][j] > d[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << k << '\n';
    for (int i = k; i >= 1; i--)
    {
        cout << Max[i] << ' ';
    }
    return 0;
}
