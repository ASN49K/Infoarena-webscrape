#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n , m , i , a[1028] , b[1028] , dp[1500][1500] , j , d[1205] , k;

int main()
{
    f >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        f >> a[i];
    for (int i = 1 ; i <= m ; i++)
        f >> b[i];

    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max (dp[i - 1][j] , dp[i][j - 1]);
    g << dp[n][m] << '\n';
    i = n , j = m;
    while (dp[i][j])
    {
        if (a[i] == b[j])
        {
            k++;
            d[k] = a[i];
            i-- , j--;
        }
        else
            if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }
    for (int i = k ; i >= 1 ; i--)
        g << d[i] << " ";
    return 0;
}
