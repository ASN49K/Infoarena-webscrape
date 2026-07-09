#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int v1[1025], v2[1025];
int n, m;

void citire(){
    in >> n >> m;
    for(int i = 0;i < n;i++){
        in >> v1[i];
    }

    for(int i = 0;i < m;i++){
        in >> v2[i];
    }

}

int LSC(int a[], int b[], int n, int m){
    int dp[n][m];
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

void reconstruct_LSC(int a[], int b[], int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> rez;
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            rez.push_back(a[i - 1]);
            i --;
            j --;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(rez.begin(), rez.end());
    for(auto i : rez){
        out << i << ' ';
    }
}

int main() {
    citire();
    out << LSC(v1, v2, n, m) << '\n';
    reconstruct_LSC(v1, v2, n, m);
    return 0;
}
