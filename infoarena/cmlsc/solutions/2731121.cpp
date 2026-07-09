#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m , n;
int a[1025] , b[1025] , dp[1025][1025] , sub[1025];

int main()
{
    f>>m>>n;
    for(int i = 1 ; i <= m ; ++i){
        f>>a[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        f>>b[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    g<<dp[m][n]<<endl;
    int  i = m , j = n;
    int k = 0;
    while(i >= 1 && j >= 1){
        if(a[i] == b[j])
            sub[++k] = a[i--] , --j;
        else if(dp[i-1][j] > dp[i][j-1])
            --i;
        else --j;
    }
    for(int p = k ; p >= 1  ; --p){
        g<<sub[p]<<" ";
    }
    return 0;
}
