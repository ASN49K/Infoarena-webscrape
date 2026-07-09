#include <bits/stdc++.h>
#define Nmax 1050

using namespace std;

int a[Nmax], b[Nmax], dp[Nmax][Nmax], n, m;
stack <int> st;

void Citire()
{
    ifstream f("cmlsc.in");
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];
    for(int i = 1; i <= m; i++)
        f >> b[i];
    f.close();
}

void LCS()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
        }
    }
    int i = n;
    int j = m;
    while(dp[i][j] != 0)
    {
        if(a[i] == b[j])
        {
            st.push(a[i]);
            i--;
            j--;
        }
        else
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
    }
    ofstream g("cmlsc.out");
    g << dp[n][m] << "\n";
    while(!st.empty())
    {
        g << st.top() << " ";
        st.pop();
    }
    g << "\n";
    g.close();
}

int main()
{
    Citire();
    LCS();
    return 0;
}
