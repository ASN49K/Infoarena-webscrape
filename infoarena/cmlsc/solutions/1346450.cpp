#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N, M, a[1050], b[1050], dp[1050][1050], sol[1050], nr;

int main()
{
    f>>N>>M;
    for (int i=1; i<=N; ++i)
        f>>a[i];
    for (int i=1; i<=M; ++i)
        f>>b[i];

    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    for (int i=N, j=M; i; )
        if (a[i]==b[j]) --i, --j, sol[++nr]=a[i];
            else if (dp[i-1][j]>dp[i][j-1]) --j;
                else --i;

    g<<nr<<'\n';
    for (int i=1; i<=nr; ++i)
        g<<sol[i]<<' '; g<<'\n';
    return 0;
}
