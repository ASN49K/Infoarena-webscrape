#include <bits/stdc++.h>
#define in "cmlsc.in"
#define out "cmlsc.out"
using namespace std;
ifstream fin(in);
ofstream fout(out);

int n,m;
int a[1030];
int b[1030];
int dp[1030][1030];
stack <int> st;

void Read()
{
    int i;

    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
}

void Dyn()
{
    int i,j;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    fout << dp[n][m] << "\n";
    for (i = n, j = m; i >= 1 && j >= 1;)
        if (a[i] == b[j])
        {
            st.push(a[i]);
            i--; j--;
        }
        else
        {
            if (dp[i-1][j] > dp[i][j-1]) i--;
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
    Dyn();

    fin.close();
    fout.close();
    return 0;
}
