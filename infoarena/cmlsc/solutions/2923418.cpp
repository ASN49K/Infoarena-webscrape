#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1026;

int N, M;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
pair < int, int > sol[NMAX][NMAX];

int mymax(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    fin >> N >> M;
    for(int i = 1; i <= N; ++i)
        fin >> a[i];
    for(int i = 1; i <= M; ++i)
        fin >> b[i];

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if(dp[i - 1][j] > dp[i][j - 1])
                dp[i][j] = dp[i - 1][j], sol[i][j] = sol[i - 1][j];
            else dp[i][j] = dp[i][j - 1], sol[i][j] = sol[i][j - 1];

            if(dp[i][j] < dp[i - 1][j - 1] + (a[i] == b[j] ? 1 : 0)) {
                if(a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1, sol[i][j] = {i - 1, j - 1};
                else dp[i][j] = dp[i - 1][j - 1], sol[i][j] = sol[i - 1][j - 1];
            }

        }
    }

    fout << dp[N][M] << '\n';
    int x = sol[N][M].first;
    int y = sol[N][M].second;
    stack < int > q;
    while(x) {
        q.push(a[x]);
        x = sol[x][y].first;
        y = sol[x][y].second;
    }
    while(!q.empty())
        fout << q.top() << ' ', q.pop();

    fout << '\n';
    return 0;
}
