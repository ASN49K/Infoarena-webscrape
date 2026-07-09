#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v1[1001], v2[1001], dp[1001][1001];
vector<int> rsp;

int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v1[i];
    for(int i = 1; i <= m; i++)
        fin >> v2[i];

    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = m;

    while(true){
        if(rsp.size() == dp[n][m])
            break;
        else{
            if(v1[i] == v2[j])
                rsp.push_back(v1[i]), i--, j--;
            else{
                if(dp[i-1][j] == dp[i][j])
                    i--;
                else
                    j--;
            }
        }
    }

    fout << dp[n][m] << '\n';

    for(int i = rsp.size() - 1; i >= 0; i--)
        fout << rsp[i] << ' ';
}