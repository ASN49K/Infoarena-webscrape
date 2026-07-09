#include <iostream>

using namespace std;
int v1[1025];
int v2[1025];
int dp[1025][1025];
int vf[1025];
int main()
{
    int m, n, i, j, k = 0;
    cin >> m >> n;
    for(i = 1; i <= m; i++)
    {
        cin >> v1[i];
    }
    for(j = 1; j <= n; j++)
    {
        cin >> v2[j];
    }
    i = 1;
    j = 1;
    while(i <= m && j <= n)
    {
        if(v1[i] == v2[j])
        {
            dp[i][j] = dp[i-1][j-1] + 1;
            j++;
        }
        else
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            j++;
        }
        if(j == n + 1)
        {
            i++;
            j = 1;
        }
    }
  //  cout << i << " " << j;
   // cout << endl;
  /*  for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    i = m;
    j = n;
    while(dp[i][j] > 0)
    {
        if(v1[i] == v2[j])
        {
            k++;
            vf[k] = v1[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    cout << k;
    cout << endl;
    for(i = k; i >= 1; i--)
    {
        cout << vf[i] << " ";
    }
    return 0;
}
