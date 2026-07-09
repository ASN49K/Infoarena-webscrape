#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N, M, a[1030], b[1030], dp[1030][1030], sol[1030], dim;

int main()
{
    f>>N>>M;
    for (int i=1; i<=N; ++i)f>>a[i];
    for (int i=1; i<=M; ++i)f>>b[i];

    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    for (int i=N, j=M; i; )
        if (a[i]==b[j]) sol[++dim]=a[i], --i, --j;
            else if (dp[i-1][j]>dp[i][j-1]) --i;
                else --j;

    g<<dim<<'\n';
    for (int i=dim; i; --i)
        g<<sol[i]<<' ';
    return 0;
}
