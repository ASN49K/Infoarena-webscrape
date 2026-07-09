#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <bitset>

using namespace std;

const int N = 1030;
int a[N], b[N], dp[N][N];
vector <int> ans;

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n,m,i,j;
    scanf("%d %d", &n, &m);
    for(i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(i = 1;i <= m;i++){
        scanf("%d", &b[i]);
    }
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int mx = dp[n][m];
    printf("%d\n", mx);
    for(i = n,j = m;mx;){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
            mx--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans){
        printf("%d ", it);
    }
    return 0;
}
