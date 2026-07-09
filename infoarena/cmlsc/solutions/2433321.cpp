#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const int MAXN = 1024 + 5;

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[MAXN],b[MAXN],dp[MAXN][MAXN];

int main()
{
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        in>>a[i];
    for(int j = 1; j <= m; j++)
        in>>b[j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            if(a[i] == b[j])
                dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    vector<int>sol;
    int i = n,j = m,valoare = dp[i][j];
    while(valoare >= 1){
        if(dp[i][j] == dp[i - 1][j - 1] + 1 && a[i] == b[j]){
            sol.push_back(a[i]);
            i--;
            j--;
            valoare--;
        }
        else if(dp[i][j] == dp[i - 1][j] && i >= 1)
            i--;
        else if(dp[i][j] == dp[i][j - 1] && j >= 1)
            j--;

    }
    reverse(sol.begin(),sol.end());
    out<<sol.size()<<"\n";
    for(auto numar : sol)
        out<<numar<<" ";
    return 0;
}
