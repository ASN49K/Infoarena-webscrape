#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

ifstream in { "cmlsc.in" };
ofstream out { "cmlsc.out" };

#define N_MAX 1030

int n, m;
int a[N_MAX], b[N_MAX];
int dp[N_MAX][N_MAX];

void gaseste_sclm() {
    for (int i { 1 }; i <= n; ++i)
        for (int j { 1 }; j <= m; ++j)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void afiseaza_sclm() {
    int i { n }, j { m };
    int sol[N_MAX], vf { 0 };
    while (i && j) {
        if (a[i] == b[j]) {
            sol[++vf] = a[i];
            --i;
            --j;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }
    
    while (vf)
        out << sol[vf--] << ' ';
}

int main() {
    in >> n >> m;
    auto citeste = [](int a[], int n) { for (int i { 1 }; i <= n; ++i) in >> a[i]; };
    citeste(a, n);
    citeste(b, m);
    
    gaseste_sclm();
    out << dp[n][m] << '\n';
    afiseaza_sclm();
    
}
