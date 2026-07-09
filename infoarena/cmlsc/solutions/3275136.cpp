#include <bits/stdc++.h>
using namespace std;


ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMax = 1024;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main()
{
    fin >> M >> N;

    for (i = 1; i <= M; ++i)
        fin >> A[i];

    for (i = 1; i <= N; ++i)
        fin >> B[i];

    for (i = 1; i <= M; ++i)
        {
        for (j = 1; j <= N; ++j)
        {
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
    }

    for (i = M, j = N; i;)
        {
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
    }

    fout << bst << endl;
    for (i = bst; i; --i)
        fout << sir[i] << " ";

    fout << endl;

    return 0;
}
