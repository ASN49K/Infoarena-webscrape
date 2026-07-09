#include <iostream>
#include <fstream>
using namespace std;

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main()
{
    int i, j;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>M>>N;
    for(i=1;i<=M;i++)
        fin>>A[i];
    for(i=1;i<=N;i++)
        fin>>B[i];
    for(i=1;i<=M;i++)
        for(i=1;i<=N;i++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else
            if (D[i-1][j] < D[i][j-1])
                --j;
            else
                --i;
    fout<<bst<<'\n';
    for (i = bst; i>0;i--)
        fout<<sir[i];
    return 0;
}
