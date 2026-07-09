#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int a[1025], b[1025], t[1025][1025];
int n, m;
void debug()
{
    int i, j;
    cout << ' ';
    for (j = 1; j <= m; j++)
        cout << b[j];
    cout << '\n';
    for (i = 1; i <= n; i++)
    {
        cout << a[i];
        for (j = 1; j <= m; j++)
            cout << t[i][j];
        cout << '\n';
    }
}

void afisare(int i, int j)
{
    if (!i || !j)
        return;
    if (a[i] == b[j])
    {
        afisare(i-1,j-1);
        cout << a[i] << ' ';
    }
    else if (t[i-1][j] >= t[i][j-1])
    {
        afisare(i-1,j);
    }
    else
    {
        afisare(i,j-1);
    }
}
int main()
{
    ifstream cin("cmlsc.in");
    //ofstream cout("cmlsc.out");
    freopen("cmlsc.out", "w", stdout);

    int i, j;

    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (j = 1; j <= m; j++)
        cin >> b[j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            t[i][j] =  max(t[i][j-1], t[i-1][j]) + (a[i] == b[j]);
    //debug();

    cout << t[n][m] << '\n';
    afisare(n, m);

    return 0;
}
