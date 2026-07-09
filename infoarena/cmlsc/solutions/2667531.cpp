#include <bits/stdc++.h>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int m, n, a[1025], b[1025], rez[1025];
int dp[1025][1025];

void rezolvare()
{
    for(int i = 1; i<=m; i++)
    {
        for(int j = 1 ; j<=n ;j++)
        {
            if(a[i]==b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int l = dp[m][n];
    int i = m, j = n;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            rez[l-1] = a[i];
            i--;
            j--;
            l--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-i])
                i--;
            else
                j--;
        }
    }
}


int main()
{
    fi>>m>>n;
    for(int i = 1;i <= m; i++)
        fi>>a[i];

    for(int i = 1;i <= n; i++)
        fi>>b[i];

    rezolvare();

    int l = dp[m][n];

    fo<<l<<endl;
    for(int i =0; i<l;i++)
        fo<<rez[i]<<" ";

    /*cout<<endl;
    for(int i=0 ; i<=m ;i++)
    {

        for(int j = 0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/

    fi.close();
    fo.close();
    return 0;
}
