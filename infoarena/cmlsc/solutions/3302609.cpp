#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector<int> v, a, solution;

void find_sol(vector<vector<int>> &dp, int i, int j){

    if(i == 0 || j == 0 )
        return;

    if(v[i - 1] == a[j - 1]){
        solution.push_back(v[i - 1]);
        find_sol(dp, i - 1, j - 1);
    } else if(dp[i - 1][j] > dp[i][j - 1]){
        find_sol(dp, i - 1, j);
    } else {
        find_sol(dp, i, j - 1);
    }
}

void solve(vector<vector<int>> &dp, int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v[i - 1] == a[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    fout << dp[n][m] << '\n';

    find_sol(dp, n, m);

    for(int i = solution.size() - 1; i >= 0; i--){
        fout << solution[i] << " ";
    }
    fout << '\n';
}

int main(){
    int n, m, x;

    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v.push_back(x);
    }

    for(int j = 1; j <= m; j++){
        fin >> x;
        a.push_back(x);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    solve(dp, n ,m);
}