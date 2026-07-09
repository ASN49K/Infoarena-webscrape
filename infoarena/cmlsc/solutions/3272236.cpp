#include <iostream>
#include <fstream>
using namespace std;

/**
A = aaabcd
B = agahbdert

Top-down
  a g a h b d e r t
a 1 1 1 1 1 1 1 1 1
a 1 1 2 2 2 2 2 2 2
a 1 1 2 2 2 2 2 2 2
b 1 1 2 2 3 3 3 3 3
c 1 1 2 2 3 3 3 3 3
d 1 1 2 2 3 4 4 4 4

dbaa
    i
aaabc
agahb
    j
dp[i][j] = lungimea maxima a unui subsir comun
    care foloseste primele i car din A si primele j din B
Sol: dp[n][m]

Recurente:
dp[i][j] = 1 + dp[i-1][j-1], daca A[i] = B[j]
         = max(dp[i-1][j], dp[i][j-1]), daca A[i] != B[j]
*/
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
char A[1003], B[1003];
int n, m;
int dp[1003][1003];

int main()
{
    int i, j;
    fin >> (A + 1);
    fin >> (B + 1);

    n = strlen(A + 1);
    m = strlen(B + 1);

    /// bottom-up
    for (i = n; i >= 1; i--)
        for (j = m; j >= 1; j--)
            if (A[i] == B[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);

    i = j = 1;
    while (i <= n && j <= m)
    {
        if (A[i] == B[j])
        {
            fout << A[i];
            i++; j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1]) i++;
        else j++;
    }
    fout.close();

    return 0;
}
