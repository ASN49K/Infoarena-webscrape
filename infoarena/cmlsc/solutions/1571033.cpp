#include <fstream>
#include <algorithm>
#define NMAX 1025

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[NMAX], b[NMAX], DP[NMAX][NMAX], sol[NMAX];
int n, m, contor = 1;

void citire ();
void LCS ();

int main()
{
    citire ();
    LCS ();
    return 0;
}

void citire ()
{
    int i;
    fin >> n >> m;
    for (i = 1; i <= n; i++) fin >> a[i];
    for (i = 1; i <= m; i++) fin >> b[i];
}

void LCS()
{
    int i, j, contor = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max (DP[i-1][j], DP[i][j-1]);

    fout << DP[n][m] << '\n';
    while (n && m)
    {
        if (a[n] == b[m])
        {
            sol[contor++] = a[n];
            n--, m--;
        }
        else if (DP[n-1][m] > DP[n][m-1]) n--;
            else m--;
    }
    for (i = contor-1; i >= 1; i--) fout << sol[i] << ' ';
    fout << '\n';
}
