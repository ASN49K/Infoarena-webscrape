#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024 + 5;

int n, m;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
int father[NMAX], k;
bool viz[NMAX][NMAX];

void Read()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
}

int Back(int i, int j)
{
    if (i > n)
        return 0;
    if (j > m)
        return 0;

    if (viz[i][j])
        return dp[i][j];
    viz[i][j] = true;
    int &ans = dp[i][j];


    if (a[i] == b[j])
    {
        father[++k]=a[i];
        ans = 1 + Back(i + 1, j + 1);
    }
    else
    {
        ans = max(Back(i + 1, j), Back(i, j + 1));
    }

    return ans;
}

int main()
{
    Read();
    fout << Back(1, 1) << "\n";
    for (int i = k; i; --i) fout << father[i] << " ";
    return 0;
}
