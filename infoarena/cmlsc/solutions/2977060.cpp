#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v[1024][1024];
int a[1024];
int b[1024];
int c[1024];
int main()
{
    int n, m;
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
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i][j - 1], max(v[i - 1][j], v[i - 1][j - 1]));
        }
    }
    cout << v[n][m] << "\n";
    int l = v[n][m];
    int i = n;
    int j = m;
    while (v[i][j] != 0)
    {
        if (a[i] == b[j])
        {
            c[l] = a[i];
            i--;
            j--;
            l--;
        }
        else
        {
            if (v[i - 1][j] >= v[i][j - 1])
                i--;
            else
                j--;
        }
    }
    for (int i = 1; i <= v[n][m]; i++)
        cout << c[i] << " ";
}