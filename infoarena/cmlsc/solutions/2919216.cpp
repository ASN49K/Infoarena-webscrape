#include <bits/stdc++.h>

using namespace std;

int A[1025], B[1025], dp[1025][1025];
int antA[1025][1025], antB[1025][1025];
int ans[1025];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int m, n, cnt;
    int gasitA, gasitB;
    int maxAns = 0;

    gasitA = gasitB = 0;

    fin >> m >> n;

    for(int i = 1; i <= m; i++)
        fin >> A[i];

    for(int j = 1; j <= n; j++)
        fin >> B[j];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            if(dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                antA[i][j] = antA[i][j - 1];
                antB[i][j] = antB[i][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
                antA[i][j] = antA[i - 1][j];
                antB[i][j] = antB[i - 1][j];
            }

            if(A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if(maxAns < dp[i][j]) {
                    maxAns = dp[i][j];
                    gasitA = i;
                    gasitB = j;
                }

                antA[i][j] = i;
                antB[i][j] = j;
            }
        }

    fout << dp[gasitA][gasitB] << '\n';

    cnt = 0;
    while(gasitA && gasitB) {
        ans[++cnt] = A[gasitA];
        if(antA[gasitA][gasitB] == gasitA && antB[gasitA][gasitB] == gasitB) {
            int aux = gasitA;
            gasitA = antA[gasitA - 1][gasitB - 1];
            gasitB = antB[aux][gasitB - 1];
        }
        int aux = gasitA;
        gasitA = antA[gasitA][gasitB];
        gasitB = antB[aux][gasitB];
    }

    for(int i = cnt; i; i--)
        fout << ans[i] << " ";

    return 0;
}
