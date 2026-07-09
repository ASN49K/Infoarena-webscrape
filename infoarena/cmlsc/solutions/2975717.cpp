#include <bits/stdc++.h>

using namespace std;

int dp[1024][1024];
int v[1024], v1[1024];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    int n, k; fin >> n >> k;
    for(int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    for(int i = 1; i <= k; i++) {
        fin >> v1[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(v[i] == v1[j])  {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    fout << dp[n][k] << "\n";
    int i = n;
    int j = k;
    vector<int> vec;
    while(i && j) {
        if(v[i] == v1[j]) {
            vec.emplace_back(v[i]);
            i--;
            j--;
        } else if(dp[i-1][j] < dp[i][j-1]){
            j--;
        } else {
            i--;
        }
    }
    reverse(vec.begin(), vec.end());
    for(auto x : vec) {
        fout << x << " ";
    }
    return 0;
}
