#include <fstream>
#define FOR(i, a, b) for(i = a; i <= b; ++i)
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, A[1025], B[1025], DP[1025][1025], SOL[1025], nsol, i, j;

int main()
{
    in >> n >> m;
    FOR(i, 1, n)
        in >> A[i];
    FOR(i, 1, m)
        in >> B[i];
    FOR(i, 1, n)
        FOR(j, 1, m)
            if(A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] +1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
    i = n, j = m;
    while(i && j)
    {
        if(A[i] == B[j])
            SOL[++nsol] = A[i],
            i--, j--;
        else
            if(DP[i-1][j] > DP[i][j-1])
                i--;
            else
                j--;
    }
    out << nsol << '\n';
    while(nsol)
        out << SOL[nsol--] << ' ';
    in.close(), out.close();
    return 0;
}
