#include<fstream>
using namespace std;
#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int M, N, a[NMax], b[NMax], D[NMax][NMax], sir[NMax], bst;
int main()
{   int i,j;
    f>>M>>N;
    FOR (i, 1, M) f>>a[i];
    FOR (i, 1, N) f>>b[i];
    FOR (i, 1, M)
        FOR (j, 1, N)
            if (a[i] == b[j]) D[i][j] = 1 + D[i-1][j-1];
            else D[i][j] = maxim(D[i-1][j], D[i][j-1]);
    for (i = M, j = N; i; )
        if (a[i] == b[j]) sir[++bst] = a[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1]) --j;
        else --i;
    g<<bst<<'\n';
    for(int i=bst;i;--i) g<<sir[i]<<" ";
    g.close(); return 0;
}
