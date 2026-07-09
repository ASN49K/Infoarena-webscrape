#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int A[1030], B[1030];
int D[1030][1030];
pair<int, int> T[1030][1030];

void rec(int x, int y)
{
    if (x == 0 && y == 0) return;
    rec(T[x][y].first, T[x][y].second);
    if (T[x][y] == make_pair(x - 1, y - 1))
        printf("%d ", A[x]);

}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &B[i]);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
            {
                D[i][j] = D[i - 1][j - 1] + 1;
                T[i][j] = make_pair(i - 1, j - 1);
            }
            else
            {
                if (D[i - 1][j] > D[i][j - 1])
                {
                    D[i][j] = D[i - 1][j];
                    T[i][j] = make_pair(i - 1, j);
                }
                else
                {
                    D[i][j] = D[i][j - 1];
                    T[i][j] = make_pair(i, j - 1);
                }
            }

    printf("%d\n", D[N][M]);
    rec(N, M);
}
