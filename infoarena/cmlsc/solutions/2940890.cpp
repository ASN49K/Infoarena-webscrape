#include <iostream>
#include <fstream>
using namespace std;
int v1[1025];
int v2[1025];
int dp[1025][1025];
int vf[1025];

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int m, n, i, j, k = 0;
    in >> m >> n;
    for(i = 1; i <= m; i++)
    {
        in >> v1[i];
    }
    for(j = 1; j <= n; j++)
    {
        in >> v2[j];
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
    out << k;
    out << endl;
    for(i = k; i >= 1; i--)
    {
        out << vf[i] << " ";
    }
    return 0;
}
