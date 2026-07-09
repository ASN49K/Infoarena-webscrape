#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define nmax 1029

int v1[nmax], v2[nmax];
int n, m;
int dp[nmax][nmax];
stack <int> s;

void solve(){

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v1[i] == v2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    fout << dp[n][m] << '\n';

    int i = n;
    int j = m;
    while(i > 0 && j > 0){
            if(v1[i] == v2[j]){
                s.push(v1[i]);
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else j--;
    }

    while(!s.empty()){
        fout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> v1[i];
    }

    for(int i = 1; i <= m; i++){
        fin >> v2[i];
    }

    solve();

    return 0;
}
