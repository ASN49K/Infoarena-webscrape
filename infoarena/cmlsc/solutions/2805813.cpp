///cel mai mare lexicografic subsir comun
#include <fstream>
#define N 1030
#include <iostream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A[N], B[N], din[N][N], ma = 0;

void solve(int m, int n, int lg)
{
    int l = 0, c = 0;
    ma = 0;
    for (int i = 1;i <= m;++i)
        for (int j = 1;j <= n;++j)
            if (A[i] == B[j] && lg == din[i][j])
            {
                if (A[i] > ma)
                {
                    ma = A[i];
                    l = i;
                    c = j;
                }
            }
    if (ma && din[l][c])
    {
        g << A[l] << ' ';
        solve(l - 1, c - 1, lg - 1);
    }
}
int main()
{
    int a, b;
    f >> a >> b;
    for (int i = a;i >= 1;--i) f >> A[i];
    for (int j = b;j >= 1;--j) f >> B[j];
    for (int i = 1;i <= a;++i)
        for (int j = 1;j <= b;++j)
            if (A[i] == B[j])
                din[i][j] = 1 + din[i - 1][j - 1];
            else
                din[i][j] = max(din[i - 1][j], din[i][j - 1]);
    g << din[a][b] << '\n';
    solve(a, b, din[a][b]);
    f.close();
    g.close();
    return 0;
}