#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1025
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;
int main(void)
{   int i, j;
    f>>M>>N;
    FOR (i, 1, M) f>>A[i]; 
    FOR (i, 1, N) f>>B[i]; 
    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1]) --j; else --i;
    g<<bst<<'\n';  
    for (i = bst; i; --i) g<<sir[i]<<' ';
	g<<'\n'; g.close(); return 0;
}

