#include <fstream>
#define NMax 1024
using namespace std;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;
 
int main(void)
{
    int i, j;
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    freopen("cmlsc.out", "w", stdout);
    f>>M>>N;
    for(int i = 1; i<=M; i++)
        f>>A[i];
    for(int i = 1; i<=N; i++)
        f>>B[i];
    for(i = 1; i <=M; i++)
        for(j = 1; j <=N; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);
 
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    g<<bst;
    for (i = bst; i; --i)
        g<<sir[i];
 
    return 0;
}