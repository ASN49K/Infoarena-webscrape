#include<cstdio>
#include<algorithm>
#include <vector>

using namespace std;
int a[1025],b[1025];
int dp[1025][1025], parent[1025][1025];
int n, m;
void citire(){
    freopen("cmlsc.in", "r", stdin);
    scanf("%d %d ",&n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d ",&a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d ",&b[i]);
}
void solve(){
    dp[0][0]=0;
    int i, j;
    int best = 0, _i, _j;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j){ //ATENTIE LA EROAREA ASTA, am vazut ca ai mai facut-o!!!!!{
            if(a[i]==b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1],
                parent[i][j] = 1;
            else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j],
                    parent[i][j] = 2;
                else
                    dp[i][j] = dp[i][j - 1],
                    parent[i][j] = 3;
            }
            
            if (best < dp[i][j])
                best = dp[i][j],
                _i = i,
                _j = j;
        }

    printf ("%d\n", best);
    
    vector<int> result;

    while (parent[_i][_j]) {
        if (a[_i] == b[_j])
            result.push_back(a[_i]);
        switch(parent[_i][_j]) {
            case 1: _i--; --_j; break;
            case 2: _i--; break;
            case 3: _j--; break;
            default: break;
        }

    }

    for (int i = result.size() - 1; i >= 0; --i)
        printf ("%d ", result[i]);
    printf ("\n");
}
int main(){
    freopen("cmlsc.out", "w", stdout);
    citire();
    solve();
}
