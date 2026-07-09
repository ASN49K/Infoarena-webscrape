#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1026][1026];
int a[1025], b[1025];

stack<int>st;

int main()
{
    int n, m, i, j;
    fin>>n>>m;

    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }

    for(i=1; i<=m; i++)
    {
        fin>>b[i];
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    i=n;
    j=m;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            st.push(a[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    fout<<dp[n][m]<<'\n';
    while(!st.empty())
    {
        fout<<st.top()<<' ';
        st.pop();
    }

    fin.close();
    fout.close();
    return 0;
}
