#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1030;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[NMAX][NMAX];
int n,m;
int a[NMAX],b[NMAX];
pair<int,int> prevs[NMAX][NMAX];
vector<int> rasp;

int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++) fin >> a[i];
    for(int i=1;i<=m;i++) fin >> b[i];

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                prevs[i][j] = {i-1,j-1};
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                if(dp[i-1][j] > dp[i][j-1]){
                    prevs[i][j] = {i-1,j};
                } else {
                    prevs[i][j] = {i,j-1};
                }
            }
        }
    }

    fout << dp[n][m] << '\n';
    int x = n;
    int y = m;
    while(x != 0 and y != 0){
        if (prevs[x][y].first == x-1 and prevs[x][y].second == y-1){
            rasp.push_back(a[x]);
        }
        pair<int,int> aux = prevs[x][y];
        x = aux.first;
        y = aux.second;
    }
    for(int i=rasp.size()-1;i>=0;i--){
        fout << rasp[i] << ' ';
    }

    return 0;
}
