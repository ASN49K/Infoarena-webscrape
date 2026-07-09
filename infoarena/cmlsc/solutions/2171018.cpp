#include <iostream>
#include <fstream>

using namespace std;

ifstream fcin("cmlsc.in");
ofstream fcout("cmlsc.out");

int n, m;
int x[1026], y[1026], z[1026], l;
int C[1026][1026];

int main()
{

    fcin >> n >> m;
    for (int i = 0; i < n; ++i)
        fcin >> x[i];
    for (int i = 0; i < m; ++i)
        fcin >> y[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (x[i - 1] == y[j - 1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);

    int i = n, j = m;
    while (i)
    {
        if (x[i - 1] == y[j - 1])
        {
            z[l++] = x[i - 1];
            --i;
            --j;
        }
        else
            if (C[i-1][j] < C[i][j-1])
                --j;
            else
                --i;
    }

    for (int i = 0; i < l / 2; ++i)
    {
        int tmp = z[i];
        z[i] = z[l - i - 1];
        z[l - i - 1] = tmp;
    }

    fcout << l << endl;
    for (int i = 0; i < l; ++i)
        fcout << z[i] << ' ';
}
