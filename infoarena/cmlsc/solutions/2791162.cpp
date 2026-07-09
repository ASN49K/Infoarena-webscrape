#include<bits/stdc++.h>
using namespace std;
int dp[1026][1026], s1[1026], s2[1026], v[1026];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main() {
    int n1, n2, i, j;
    f >> n1 >> n2;
    for(i = 1; i <= n1; i++) f >> s1[i];
    for(i = 1; i <= n2; i++) f >> s2[i];
    for(i = 1; i <= n1; i++) {
        for(j = 1; j <= n2; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    g << dp[n1][n2] << '\n';
    i = n1;
    j = n2;
    while(i != 0 && j != 0) {
        if(dp[i-1][j-1] + 1 == dp[i][j]){
            v[++v[0]] = s1[i];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }
    for(i = v[0]; i > 0; i--) g << v[i] << ' ';
    return 0;
}