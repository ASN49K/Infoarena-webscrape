#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n , m;
int a[1025] , b[1025];

int main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++) fin >> a[i];
    for(int i = 1 ; i <= m ; i++) fin >> b[i];
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        }
    }
    int maxi = dp[n][m];
    fout << maxi << '\n';
    vector<int> rez;
    int i = n , j = m;
    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            rez.push_back(a[i]);
            i-- , j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]) i--;
        else j--;
    }
    reverse(rez.begin() , rez.end());
    for(auto i : rez) fout << i <<" ";
    return 0;
}
