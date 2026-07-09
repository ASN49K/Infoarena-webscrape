#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int m,n,a[256], b[256];
    int dp[256][256] = {0};
    int v[256];

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f>>m>>n;

    for(int i = 1; i<=m; i++){
        f>>a[i];
    }

    for(int i = 1; i<= n; i++){
        f>>b[i];
    }

    for(int i = 1; i <= m; i++){
        for( int j = 1 ; j <= n; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    g<<dp[m][n]<<endl;

    int i = m, j = n;
    int k = 0;

    while(i>0 && j>0){
        if(a[i] == b[j]){
            v[k++] = a[i];
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    for(int t = k-1; t>=0; t--){
        g<<v[t]<<" ";
    }

    f.close();
    g.close();
    return 0;
}
