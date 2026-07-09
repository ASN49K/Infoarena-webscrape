#include <bits/stdc++.h>
using namespace std;
#define MAXN 1024

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[MAXN + 1];
int b[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

stack<int> sol;

int main(){
    int n,m,i,j;

    fin >> n >> m;

    for (i = 1; i <= n; i ++){
        fin >> a[i];
    }

    for (i = 1; i <= m; i ++){
        fin >> b[i];
    }

    for (i = 1; i <= n; i ++){
        for (j = 1; j <= m; j ++){
            dp[i][j] = (a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j],dp[i][j - 1]));
        }
    }

    i = n;
    j = m;
    while (i && j){
        if (a[i] == b[j]){
            sol.push(a[i]);
            i --;
            j --;
        }
        else{
            if (dp[i - 1][j] > dp[i][j - 1]){
                i --;
            }
            else{
                j --;
            }
        }
    }

    fout << sol.size() << '\n';

    while (!sol.empty()){
        fout << sol.top() << ' ';
        sol.pop();
    }

    fin.close();
    fout.close();

    return 0;
}
