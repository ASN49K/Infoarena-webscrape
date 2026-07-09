#include <iostream>
#include <fstream>

#define max_len 1024
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    int a[max_len][max_len] = {0, 0};
    int x[max_len], y[max_len], sir[max_len];
    int n, m, k;
    int i, j;


    f >> n >> m;

    for (i = 1; i <= n; i++)
        f >> x[i];

    for (i = 1; i <= m; i++)
        f >> y[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (x[i] == y[j])
                a[i][j] = 1 + a[i-1][j-1];
            else
                a[i][j] = maxim(a[i-1][j], a[i][j-1]);

    k = 0;
    for (i = m, j = n; i; )
        if (x[i] == y[j])
        {
            sir[++k] = x[i];
            i--;
            j--;
        }
        else if (a[i-1][j] < a[i][j-1])
            j--;
        else
            i--;

    for (i = k; i >= 1; i--)
        g << sir[i] << endl;

    return 0;
}
