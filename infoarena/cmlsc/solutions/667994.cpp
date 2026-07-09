#include<fstream>
using namespace std;
#define MAX 1025
#define filein "cmlsc.in"
#define fileout "cmlsc.out"
#define Max(a,b) ((a > b) ? a : b)
int A[MAX], B[MAX], N, M, D[MAX][MAX], SIR[MAX], Count;
FILE *fin, *fout;

int main()
{
    fin = fopen(filein, "r");
    fscanf(fin, "%d %d", &N, &M);
    for(int i = 1; i <= N; i++) fscanf(fin, "%d", &A[i]);
    for(int i = 1; i <= M; i++) fscanf(fin, "%d", &B[i]);
    fclose(fin);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = Max(D[i][j-1], D[i-1][j]);
    Count = 0;
    for(int i = N, j = M; i; )
        if(A[i] == B[j])
            SIR[++Count] = A[i], i--,j--;
        else
            if(D[i][j-1] > D[i-1][j])
                j--;
            else
                i--;

    fout = fopen(fileout, "w");
    fprintf(fout, "%d\n", Count);
    for(int i = Count; i > 0; i--)
        fprintf(fout, "%d ", SIR[i]);
    return 0;
}
