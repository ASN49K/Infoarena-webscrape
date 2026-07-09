#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int s1[1030], s2[1030];

int dp[1030][1030];

vector <int> sol;

int main(){
    int len1, len2;
    in>>len1;
    in>>len2;
    for(int i = 0; i < len1; i++)
        in>>s1[i];
    for(int j = 0; j < len2; j++)
        in>>s2[j];
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int s = dp[len1][len2];
    int a = len1, b = len2;
    while(s > 0){
        if(s1[a-1] == s2[b-1]){
            sol.push_back(a-1);
            s--;
            a--;
            b--;
        }else{
            if(dp[a-1][b] == dp[a][b]){
                a--;
            }else{
                b--;
            }
        }
    }
    out<<dp[len1][len2];
    out<<'\n';
    reverse(sol.begin(), sol.end());
    for(auto it:sol)
        out<<s1[it]<<" ";
    return 0;
}
