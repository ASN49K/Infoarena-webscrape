#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX = 1024;
int M, N, A[NMAX], B[NMAX], dp[NMAX][NMAX], from[NMAX][NMAX];
vector<int> sol;

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = 0, from[i][j] = 0;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                from[i][j] = 1; // 1 pentru diagonala
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    from[i][j] = 2; // 2 pentru sus
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    from[i][j] = 3; // 3 pentru stanga
                }
            }
        }

    int i = M, j = N;
    while (i > 0 && j > 0)
    {
        if (from[i][j] == 1)
        {
            sol.push_back(A[i - 1]);
            i--, j--;
        }
        else if (from[i][j] == 2)
            i--;
        else
            j--;
    }

    reverse(sol.begin(), sol.end());

    cout << sol.size() << "\n";
    for (auto x : sol)
        cout << x << " ";

    return 0;
}