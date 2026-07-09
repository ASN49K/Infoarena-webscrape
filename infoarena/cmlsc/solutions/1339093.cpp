#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

const int MAXN = 1025;

short A[MAXN], B[MAXN];
short D[MAXN][MAXN];
short Sol[MAXN];

inline int max2 (const short &A, const short &B)
{
    if (A > B)
        return A;

    return B;
}

int main()
{
    int N, M, i, j, k;

    in >> N >> M;
    for (i = 1; i <= N; i ++)
        in >> A[i];
    for (j = 1; j <= M; j ++)
        in >> B[j];

    for (i = 1; i <= N; i ++)
        for (j = 1; j <= M; j ++)
            if (A[i] == B[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max2 (D[i - 1][j], D[i][j - 1]);

    out << D[N][M] << "\n";
    for (i = N, j = M, k = 0; i; )
        if (A[i] == B[j]){
            Sol[++ k] = A[i];
            i --;
            j --;
        }
        else
            if (D[i][j - 1] > D[i - 1][j])
                j --;
            else
                i --;

    for ( ; k; k --)
        out << Sol[k] << " ";

    return 0;
}
