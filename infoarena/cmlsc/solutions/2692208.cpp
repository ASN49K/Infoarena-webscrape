#include <iostream>
using namespace std;

int L[1025][1025], b[2000], a[2000], unu ,doi;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j] && unu == 0)
                L[i][j] = 1 + L[i - 1][j - 1], unu = a[i];
            else if(a[i] == b[j])
                L[i][j] = 1 + L[i - 1][j - 1], doi = a[i];
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    cout << L[n][m] << '\n' << unu << ' ' << doi;
    return 0;
}
