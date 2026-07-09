#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, A[1001], B[1001], Dp[1001][1001];

void Afisare(int, int);

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> A[i];
    for (int i = 1; i <= m; ++i)
        fin >> B[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(A[i] == B[j])
                Dp[i][j] = 1 + Dp[i - 1][j - 1];
            else Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
        }
    }
    fout << Dp[n][m] << '\n';
    Afisare(n, m);

    return 0;
}

void Afisare(int x, int y)
{
    while (Dp[x - 1][y] == Dp[x][y])
        --x;
    while (Dp[x][y - 1] == Dp[x][y])
        --y;
    if (x - 1 >= 1 && y - 1 >= 1)
        Afisare(x - 1, y - 1);
    fout << A[x] << " ";
}
