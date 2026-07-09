#include <bits/stdc++.h>
#define Nmax 2048

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, a[Nmax], b[Nmax], dp[Nmax][Nmax], ans[Nmax];

inline void Read()
{
    int i;
    fin >> N >> M;
    for(i = 1; i <= N; i++) {
        fin >> a[i];
    }
    for(i = 1; i <= M; i++) {
        fin >> b[i];
    }
    fin.close();
}

inline void Solve()
{
    int i, j, head;
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    i = N;
    j = M;
    head = 0;
    while(i && j) {
        if(a[i] == b[j]) {
            ans[++head] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    fout << dp[N][M] << "\n";
    do {
        fout << ans[head] << " ";
    } while(--head);
    fout.close();
}

int main()
{
    Read();
    Solve();
    return 0;
}
