#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, DP[1025][1025], v1[1025], v2[1025];
// char s1[1001], s2[1001];

void afis(int i, int j)
{
    if (i < 1 || j < 1)
        return;

    if (i == 1 && j == 1)
    {
        if (DP[i][j] == 1)
            fout << v1[i] << " ";
        return;
    }

    if (DP[i][j] == DP[i - 1][j - 1] + 1)
    {
        afis(i - 1, j - 1);
        fout << v1[i] << " ";
    }

    else if (DP[i][j - 1] <= DP[i - 1][j])
        afis(i - 1, j);

    else
        afis(i, j - 1);
}
int main()
{
    fin >> n >> m;
    // fin >> s1 >> s2;

    // n = strlen(s1);
    // m = strlen(s2);

    for (int i = 1; i <= n; i++)
        fin >> v1[i];

    for (int j = 1; j <= m; j++)
        fin >> v2[j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // cout << i << " " << j << " ";
            if (v1[i] == v2[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;

            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
           // cout << DP[i][j] << " ";
        }
      //  cout << "\n";
    }

    fout << DP[n][m] << "\n";

    afis(n, m);

    return 0;
}