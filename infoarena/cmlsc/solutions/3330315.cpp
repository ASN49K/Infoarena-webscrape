#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    int m, n, i, j, k;
    int a[1024], b[1024], c[1024][1024] = {0}, sir[1024];
    int x = 0;

    cin >> m >> n;

    for (i = 1; i <= m; i++)
        cin >> a[i];

    for (i = 1; i <= n; i++)
        cin >> b[i];

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
            {
                if (c[i - 1][j] > c[i][j - 1])
                    c[i][j] = c[i - 1][j];
                else
                    c[i][j] = c[i][j - 1];
            }
        }

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            sir[++x] = a[i];
            i--;
            j--;
        }
        else if (c[i - 1][j] < c[i][j - 1])
            j--;
        else
            i--;
    }

    cout << x << '\n';
    for (k = x; k >= 1; k--)
        cout << sir[k] << ' ';
}
