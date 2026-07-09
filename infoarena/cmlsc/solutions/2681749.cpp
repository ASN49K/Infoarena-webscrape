#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX = 1024;

int A[NMAX + 1], B[NMAX + 1], D[NMAX + 1][NMAX + 1], sir[NMAX + 1], poz;
int N, M;

int main()
{
    f >> M >> N;
    for(int i = 1; i <= M; i++)
        f >> A[i];
    for(int i = 1; i <= N; i++)
        f >> B[i];
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            if(A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else D[i][j] = max(D[i - 1][j], D[i][j - 1]);
    int i = M, j = N;
    while(i > 0&&j>0)
        if(A[i] == B[j])
        {
            sir[++poz] = A[i];
            i--, j--;
        }
        else if(D[i - 1][j] < D[i][j - 1])
            j--;
        else i--;
    g<<poz<<'\n';
    for(int i=poz;i>=1;i--)
        g<<sir[i]<<' ';
    return 0;
}
