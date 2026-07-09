//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n , m;
int x[1026], y[1026], dp[1026][1026], sol[1026];
int main() {
    cin >> n >> m;
    for(int i =1 ;i <= n ;i ++)
        cin >> x[i];
    for(int i =1 ;i <=m; i++)
        cin >> y[i];
    int i ,j;
    for( i =1 ;i <=n ;i++)
        for( j =1 ;j <=m; j++)
        {
            if(x[i] == y[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    cout << dp[n][m]<<'\n';
        int nr = dp[n][m], nr2 = dp[n][m];
    while(nr)
    {
        if(x[n] == y[m])
        {
            nr--;
            sol[dp[n][m]] = x[n];
            n--;
            m--;
        }
        else
        {
            if(dp[n - 1][m] > dp[n][m - 1])
                n--;
            else
                m--;
        }
    }
    for( int i =1 ;i <=nr2; i++)
        cout << sol[i]<< " ";
    return 0;
}
