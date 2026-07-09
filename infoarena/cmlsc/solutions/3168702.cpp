#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX = 1025;
int a[NMAX], b[NMAX], n, m;
int d[NMAX][NMAX];

void lcs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[i])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);

}

void afis()
{
    int i = n, j = m;
    int t[NMAX];
    int k = 0;
    while (i > 0 &&j > 0)
    {
        if (a[i] == b[j])
        {
            t[++k] = a[i];
            i--;
            j--;
        }
        else if (d[i][j - 1] > d[i - 1][j])
            j--;
        else
            i--;
    }
    for (int i = n; i >= 1; i--)
        cout << t[i] << " ";

}

int main()
{
   cin >> n;
   for (int i = 1; i <= n; i++)
        cin >> a[i];

   for (int i = 1; i <= n; i++)
        cin >> b[i];

    lcs();
    afis();

    return 0;




}
