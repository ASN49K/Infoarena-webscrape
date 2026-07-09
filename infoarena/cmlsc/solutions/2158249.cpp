#include <fstream>
#include <stack>
#define file "cmlsc"
#define NM 1027
#define Max(i,j) (i > j ? i : j)

using namespace std;

ifstream fin(file".in");
ofstream fout(file".out");

short a[NM],b[NM];
short n,m;
short dp[NM][NM];

stack<short> st;

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; ++i)
        fin>>a[i];
    for(int i=1; i<=m; ++i)
        fin>>b[i];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            bool pc = (a[i] == b[j]);
            dp[i][j] = Max(Max(dp[i-1][j],dp[i][j-1]) , dp[i-1][j-1] + pc);
        }
    fout<<dp[n][m]<<"\n";

    int M = dp[n][m];
    int i = n, j = m;
    while(M > 0)
    {
        while(dp[i-1][j-1] == M) --i,--j;
        while(dp[i-1][j] == M) --i;
        while(dp[i][j-1] == M) --j;
        st.push(a[i]);
        --i;
        --j;
        --M;
    }

    while(!st.empty())
    {
        fout<<st.top()<<" ";
        st.pop();
    }

	return 0;
}
