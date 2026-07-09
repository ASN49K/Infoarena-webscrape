#include <stdio.h>
#include <algorithm>

#define MAX 1024
#define r fscanf
#define pr fprintf
#define R scanf
#define Pr printf

FILE *f, *g;

int M, N;
short int A[MAX + 1], B[MAX + 1];
short int Sol[MAX + 1];int Nr;
int d[MAX + 1][MAX + 1];

int main()  {
    f = fopen("cmlsc.in", "r");
    g = fopen("cmlsc.out", "w");

    r(f, "%d%d", &M, &N);
    for(int i = 1;i <= M;i++)
        r(f, "%hd", &A[i]);
    for(int i = 1;i <= N;i++)
        r(f, "%hd", &B[i]);

    for(int i = 1;i <= M;i++)
        for(int j = 1;j <= N;j++)  {
            if(A[i] == B[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = std::max(d[i - 1][j], d[i][j - 1]);
        }

    for(int i = M, j = N; i > 0 && j > 0;)  {
        if(A[i] == B[j])
            Sol[Nr++] = A[i], i--, j--;
        else  {
            if(d[i][j - 1] > d[i - 1][j])
                j--;
            else
                i--;
        }
    }

    pr(g, "%d\n", Nr);

    for(int i = Nr - 1;i >= 0;i--)
        pr(g, "%d ", Sol[i]);

    fclose(f);
    fclose(g);

    return 0;
}
