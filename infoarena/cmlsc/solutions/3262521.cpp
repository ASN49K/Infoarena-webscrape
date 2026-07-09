#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], dp[1025][1025], v[1025];

int main()
{
    int n, m;
    fin>>n>>m;

    for(int i = 1; i <= n; i++){
        fin>>a[i];
    }
    for(int i = 1; i <= m; i++){
        fin>>b[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n;
    int j = m;
    int k = dp[n][m];

    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            v[k] = a[i];
            i--;
            j--;
            k--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    fout<<dp[n][m]<<"\n";
    for(int i = 1; i <= dp[n][m]; i++){
        fout<<v[i]<<" ";
    }



    return 0;
}
