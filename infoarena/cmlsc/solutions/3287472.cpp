// luata de la Luca Sofronie, vreau sa vad de ce are memory usage asa mic

#include <math.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
// #include <bits/stdc++.h>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

#define pb(x) push_back(x)

const int NMAX = 1030;

int   a[NMAX], b[NMAX];
short dp[NMAX][NMAX];

int n, m;

void read()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
}

void refac_sirul(int l, int c)
{
    if (l == 0 || c == 0)
        return;
    else {
        if (a[l] == b[c])  // ma duc pe diagonala
        {
            refac_sirul(l - 1, c - 1);
            cout << a[l] << ' ';
        }
        else if (dp[l][c - 1] > dp[l - 1][c])
            refac_sirul(l, c - 1);
        else
            refac_sirul(l - 1, c);
    }
}

void solution()
{
    for (int i = 1; i <= n; ++i)  // pe linii se afla numerele din vectorul a
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[n][m] << '\n';
    refac_sirul(n, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read();
    solution();
}