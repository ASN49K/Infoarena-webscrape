#include<cstdio>
//#include "Euclid.cpp"
//#include "EuclidExtended.cpp"
//#include "LCS.cpp"

using namespace std;

#include <cstdio>
#include <algorithm>
#include <vector>

#define NMAX 1024+5
using namespace std;

class LCS {
private:
    int D[NMAX][NMAX];
    int A[NMAX];
    int B[NMAX];
    int N, M;
    int sol[NMAX];

    void lcs() {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                if (A[i] == B[j])
                    D[i][j] = 1 + D[i - 1][j - 1];
                else D[i][j] = max(D[i][j - 1], D[i - 1][j]);
            }
    }

public:
    void LCS_main() {
        freopen("cmlsc.in", "r", stdin);
        freopen("cmlsc.out", "w", stdout);

        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);

        for (int i = 1; i <= M; i++)
            scanf("%d", &B[i]);

        lcs();

        int sol0 = 0;

        for (int i = N, j = M; i;) {
            if (A[i] == B[j])
                sol[++sol0] = A[i], i--, j--;
            else if (D[i - 1][j] < D[i][j - 1])
                j--;
            else i--;
        }

        printf("%d\n", sol0);
        for (int i = sol0; i >= 1; i--)
            printf("%d ", sol[i]);

    }

} LCS;

int main()
{
    LCS.LCS_main();
    return 0;
}