#include <bits/stdc++.h>

using namespace std;
int N, M;
short DP[1050][1050];

int A[1050], B[1050];
vector<int> answer;

void read()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int j = 1; j <= M; ++j)
        cin >> B[j];
}

void dynamic()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
}

void reconst()
{
    int i = N,j = M;
    cout << DP[i][j] << "\n";
    while (i && j) {
        if (A[i] == B[j]) {
            answer.emplace_back(A[i]);
            --i;
            --j;
            continue;
        }
        if (DP[i][j-1] > DP[i-1][j])
            --j;
        else
            --i;
    }
    reverse(answer.begin(), answer.end());
    for (auto it : answer)
        cout << it << " ";
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    read();
    dynamic();
    reconst();

    return 0;
}
