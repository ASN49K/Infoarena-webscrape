#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define maxN 1030
#define PB push_back

int vA[maxN], vB[maxN];
int dp[maxN][maxN];
vector <int> sol;


int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    int A, B;
    scanf ("%d %d", &A, &B);

    for (int i = 1; i <= A; ++ i) scanf ("%d", &vA[i]);
    for (int i = 1; i <= B; ++ i) scanf ("%d", &vB[i]);

    for (int i = 1; i <= A; ++ i)
        for (int j = 1; j <= B; ++ j)
            if (vA[i] == vB[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);

    printf ("%d\n", dp[A][B]);

    for (int i = A, j = B; i && j; )
    {
        if (vA[i] == vB[j])
        {
            sol.PB (vA[i]);
            -- i, -- j;
            continue;
        }

        if (dp[i - 1][j] >= dp[i][j - 1])
        {
            -- i;
            continue;
        }
        else -- j;
    }

    for (int i = sol.size() - 1; i >= 0; -- i) printf ("%d ", sol[i]);

    return 0;
}
