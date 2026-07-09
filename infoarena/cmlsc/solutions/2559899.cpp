#include <fstream>
#include <stack>

using namespace std;

const int N = 1025;

int a[N], n, b[N], m, dp[N][N];

void Read ()
{
    ifstream fin ("cmlsc.in");
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
    fin.close();
}

void DP ()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    ofstream fout ("cmlsc.out");
    fout << dp[n][m] << "\n";
    stack <int> st;
    i = n;
    j = m;
    while (i > 1 || j > 1)
    {
        if (a[i] == b[j])
        {
            st.push(a[i]);
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    Read();
    DP();
    return 0;
}
