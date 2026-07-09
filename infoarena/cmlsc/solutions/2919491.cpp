#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1024;

int A[NMAX + 1], B[NMAX + 1];
int dp[NMAX + 1][NMAX + 1], ansV[NMAX + 1];

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int m, n;
    int ans, ansI, ansJ;

    ans = ansI = ansJ = 0;

    fin >> m >> n;

    for(int i = 1; i <= m; i++)
        fin >> A[i];

    for(int i = 1; i <= n; i++)
        fin >> B[i];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if(dp[i][j] > ans)
                    ans = dp[i][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    fout << ans << '\n';

    int cnt = 0;
    ansI = m;
    ansJ = n;

    while(ansI && ansJ) {
        if(dp[ansI][ansJ] == dp[ansI - 1][ansJ - 1] + 1) {
            ansV[++cnt] = A[ansI];
            ansI--;
            ansJ--;
        } else if(dp[ansI][ansJ] == dp[ansI - 1][ansJ]){
            ansI--;
        } else
            ansJ--;
    }

    for(int i = ans; i; i--)
        fout << ansV[i] << " ";

    fin.close();
    fout.close();

    return 0;
}
