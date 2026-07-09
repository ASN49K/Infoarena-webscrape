#include <fstream>

#define maxim(a,b) ((a>b) ? a : b)
#define NMax 1024
using namespace std;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], x = 0;

int main()
{
    int i, j;
    ifstream fin("cmlsc.in");
    fin >> M >> N;
    for (i = 1; i <= M; i++)
        fin >> A[i];
    for (i = 1; i <= N; i++)
        fin >> B[i];

    fin.close();

    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i;)
        if(A[i] == B[j])
            {sir[++x] = A[i];
            i--;
            j--;}
        else if (D[i-1][j] < D[i][j-1])
            j--;
        else
            i--;

    ofstream fout("cmlsc.out");
    fout << x <<'\n';
    for (i = x; i > 0; i--)
    {
        fout << sir[i] << ' ';
    }
fout.close();
    return 0;
}
