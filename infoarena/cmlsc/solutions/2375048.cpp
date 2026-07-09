#include <bits/stdc++.h>
#define NMax 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
    fin >> M >> N;
    for (int i=1; i<=M; i++)
        fin >> A[i];
    for (int i=1; i<=N; i++)
        fin >> B[i];

    for (int i=1; i<=M; i++)
        for (int j=1; j<+N; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);
    int i = M;
    int j = N;
    while(i)
        if (A[i] == B[j])
        {
            sir[++bst] = A[i];
            --i;
            --j;
        }
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    fout << bst << '\n';
    for (i = bst; i>0; i--)
        fout << sir[i] << " ";

    return 0;
}
