#include <fstream>
#include <iostream>
#define nmax 1030

using namespace std;

int dp[nmax][nmax], a[nmax], b[nmax], sol[nmax], n, m, k;

void Read()
{
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    fin.close();
}

void Dynamic()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                sol[++k] = a[i];
                cout << a[i] << " ";
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}

void Solve()
{
    ofstream fout("cmlsc.out");
    Dynamic();
    fout << k << "\n";
    for(int i = 1; i <= k; i++)
        fout << sol[i] << " ";
    fout << "\n";
    fout.close();
}

int main()
{
    Read();
    Solve();
    return 0;
}
