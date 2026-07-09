#include<fstream>

using namespace std;

#define Limax 1024
#define FOR(contor, start, finish) for(contor=start; contor<=finish; contor++)
#define MAXIM(a, b) ((a > b) ? a : b)

FILE*in;
ofstream out("cmlsc.out");

unsigned M, N, A[Limax], B[Limax], D[Limax][Limax], sir[Limax], nr, i, j;

void read()
{
    in=fopen("cmlsc.in", "r");
    fscanf(in, "%d%d", &M, &N);
    FOR(i, 1, M)
        fscanf(in, "%d", &A[i]);
    FOR(i, 1, N)
        fscanf(in, "%d", &B[i]);
}
int main()
{
    read();
    FOR(i, 1, M)
        FOR(j, 1, N)
            if (A[i] == B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=MAXIM(D[i-1][j], D[i][j-1]);

    i=M;
    j=N;
    while ((i) && (j))
        if (A[i] == B[j])
        {
            sir[++nr]=A[i];
            --i;
            --j;
        }
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    out<<nr<<'\n';

    for (i=nr; i>=1; i--)
        out<<sir[i]<<" ";

    return 0;
}
