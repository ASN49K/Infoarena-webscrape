#include <bits/stdc++.h>
#define newline '\n'
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
///***********************
const int NMAX = (1 << 10) + 3;
int n, m, a[NMAX], b[NMAX], best, ans[NMAX], dp[NMAX][NMAX];

void read() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];
}

void getDP() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void buildAns() {
    for (int i = n, j = m; i && j;)
        if (a[i] == b[j]) {
            ans[++best] = a[i];
            i--, j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
}

void display() {
    fout << best << newline;
    while (best)
        fout << ans[best--] << ' ';
}

int main() {
    read();
    getDP();
    buildAns();
    display();
    fout.close();
    return 0;
}
