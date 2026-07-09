#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 1025

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[N][N], a[N], b[N];

void build(vector<int> &res, int x, int y){

    if(dp[x][y] == 0) return;

    if(a[x] == b[y]){
        res.push_back(a[x]);
        build(res, x-1, y-1);
        return;
    }

    if(dp[x-1][y] > dp[x][y-1])
        build(res, x-1, y);
    else
        build(res, x, y-1);

}

int main(){
    int n, m;
    in >> n >> m;

    for(int i=1; i<=n; i++)
        in >> a[i];
    for(int i=1; i<=m; i++)
        in >> b[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    out << dp[n][m] << '\n';

    vector<int> res;
    build(res, n, m);
    reverse(res.begin(), res.end());
    for(int k : res)
        out << k << ' ';

}

