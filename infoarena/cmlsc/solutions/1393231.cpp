#include <fstream>
#include <iostream>

#define MAXN 1025
#define MAXM 1025

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

int dp[MAXM][MAXN], A[MAXM], B[MAXN], sol[MAXN];
int N, M, sol_length;

void read_input()
{
    in >> M >> N;
    int i;
    for (i = 1; i <= M; i++) in >> A[i];
    for (i = 1; i <= N; i++) in >> B[i];
}

void apply_lcs_algorithm()
{
    // find the length of the lcs
    int i, j;
    for (i = 1; i <= M; i++) 
        for (j = 1; j <= N; j++)
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

    // build solution
    for (i = M, j = N; i > 0, j > 0;) {
        if (A[i] == B[j]) {
            sol[sol_length++] = A[i];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
}

int main()
{
    read_input();
    apply_lcs_algorithm();

    // print the solution
    out << dp[M][N] << '\n';
    for (int i = sol_length - 1; i >= 0; i--) out << sol[i] << " ";
    out << '\n';

    return 0;
}