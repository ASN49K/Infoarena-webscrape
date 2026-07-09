#include <iostream>
#include<fstream>
using namespace std;
const int NMax = 1024;
int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;
ifstream fin("triunghi.in");
ofstream fout("triunghi.out");
int main()
{
int i, j;
fin >> M >> N;
for (i = 1; i <= M; ++i)
    fin >> A[i];
for (i = 1; i <= N; ++i)
    fin >> B[i];
    // Calculare matrice LCS
    for (i=1; i<=M; i++)
    {
        for (j=1; j<=N; j++)
        {
            if (A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
            {
                if (D[i-1][j]>D[i][j-1])
                    D[i][j]= D[i-1][j];
                else
                    D[i][j]=D[i][j-1];
            }
        }
    }
    // Refacere subșir comun maxim (LCS)
    i=M;
    j=N;
    while (i&&j)
    {
        if (A[i] == B[j])
        {
            sir[++bst] = A[i];
            i--;
            j--;
        } else if (D[i - 1][j] < D[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }
    // Afișare rezultat
    fout << bst << "\n";
    for (i = bst; i >= 1; --i)
        fout << sir[i] << " ";
    fout << "\n";

    return 0;
}
