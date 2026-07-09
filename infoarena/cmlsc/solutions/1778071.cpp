#include<cstdio>
#define Maxim(x, y) (x <= y ? y : x)
using namespace std;

FILE *fin = freopen("cmlsc.in", "r", stdin);
FILE *fout = freopen("cmlsc.out", "w", stdout);

const int NMax = 1025;
int N, M, nr;
int v[NMax], w[NMax], q[NMax];
int d[NMax][NMax];


int main()
    {
        scanf("%d%d", &N, &M);

        for (int i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        for (int i = 1; i <= M; i++)
            scanf("%d", &w[i]);


        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
            {
                if (v[i] == w[j])
                    d[i][j] = d[i - 1][j - 1] + 1;
                else
                    d[i][j] = Maxim(d[i - 1][j], d[i][j - 1]);
            }

        for (int i = N, j = M; i;)
        if (v[i] == w[j])
        {
            q[++ nr] = v[i];
            i--; j--;
        }
        else
            if (d[i - 1][j] < d[i][j - 1])  j--;
        else                                i--;

        printf("%d\n", nr);
        for (int i = nr; i; i--)
            printf("%d ", q[i]);
    }
