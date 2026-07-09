#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1030;

int dp[MAX][MAX], a[MAX], b[MAX];

stack<int> st;

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

    i=n, j=m;
    int len=0;

    while(i>=1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            len++;
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


    fout<<len<<'\n';
    while(!st.empty())
    {
        fout<<st.top()<<' ';
        st.pop();
    }

    fin.close();
    fout.close();
    return 0;
}
