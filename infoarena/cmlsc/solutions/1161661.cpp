#include <fstream>
#include <vector>
#include <bitset>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N, M, dp[1025][1025], A[1025], B[1025], dim, sol[1025];

int main()
{
    f>>N>>M;
    for (int i=1; i<=N; ++i) f>>A[i];
    for (int i=1; i<=M; ++i) f>>B[i];

    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            if (A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    for (int i=N, j=M; i;)
        if (A[i]==B[j]) sol[++dim]=A[i], --i, --j;
            else if (dp[i][j-1]>dp[i-1][j]) --j;
                else --i;
    g<<dim<<'\n';
    for (int i=1; i<=dim; ++i && g<<' ') g<<sol[i];
    return 0;
}
