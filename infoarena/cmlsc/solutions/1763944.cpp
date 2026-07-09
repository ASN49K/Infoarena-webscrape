#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX=1024;

int M, N, A[NMAX], B[NMAX], LCS[NMAX][NMAX], sir[NMAX], lgsir;

int main()
{
    int i, j;
    f>>M>>N;
    for (i=1; i<=M; i++)
        f>>A[i];
    for (i=1; i<=N; i++)
        f>>B[i];
    for (i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            if (A[i] == B[j])
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
        {
            sir[++lgsir] = A[i];
            i--;
            j--;
        }
        else if (LCS[i-1][j] < LCS[i][j-1])
            --j;
        else
            --i;
    g<<lgsir<<endl;
    for (i = lgsir; i; --i)
        g<<sir[i]<<' ';

    return 0;
}
