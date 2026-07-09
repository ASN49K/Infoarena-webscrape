#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v[1025], v1[1025], dp[1025][1025];
vector<int> vec;
int main(){

    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v[i];
    for(int j = 1; j <= m; j++)
        fin >> v1[j];

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){

            if(v1[i] == v[j]) dp[i][j] = dp[i - 1][j -1]+ 1, vec.push_back(v1[i]);
            else{

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    fout << dp[m][n] << '\n';
    for(auto i : vec) fout << i << " ";
}