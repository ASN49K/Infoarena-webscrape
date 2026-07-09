#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m;
    fin>>n>>m;
    int a[n+1],b[m+1];
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m ; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        }
    }
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <=m;j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    fout << dp[n][m] << '\n';
    int j = m,i=n;
    int k =0,rez[n];
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j])
            i--;
        else if(dp[i][j] == dp[i][j-1])
            j--;
        else
        if(dp[i][j] == 1+ dp[i-1][j-1])
        {

            rez[k++] = a[i];
            j--;i--;
        }
    }
    for(int i = k-1; i>=0; i--)
        fout << rez[i] << " ";
    return 0;
}
