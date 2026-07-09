#include <iostream>
#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024
#define FOR(i, a, b) for (i = a; i <= b; ++i)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main()
{
    int i,j;
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];

    for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
            else D[i][j]=maxim(D[i-1][j],D[i][j-1]);
        }
    }

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    g<<bst;
    for (i = bst; i; --i)
        g<<sir[i]<<" ";
    return 0;
}
