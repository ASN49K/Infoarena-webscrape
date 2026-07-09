#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n , m , a[1025] , b[1025] , dp[1500][1500] , i , cnt , j , sol[1055];

int main()
{
    f >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        f >> a[i];
    for (int i = 1 ; i <= m ; i++)
        f >> b[i];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max (dp[i - 1][j] , dp[i][j - 1]);
        }
    }
    i = n , j = m;
    while (dp[i][j])
    {
        if (a[i] == b[j])
        {
            cnt++;
            sol[cnt] = a[i];
            i--;
            j--;
        }
        else
        if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    g << cnt << '\n';;
    for (int i = cnt ; i >= 1 ; i--)
        g << sol[i] << " ";
    return 0;
}
