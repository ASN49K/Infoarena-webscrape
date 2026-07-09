//#include <iostream>

#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int N, M, a[1025], b[1025], dp[1025][1025], ut[1025][1025], i, j, ans[1025];

int main(){
    cin >> N >> M;
    for(i = 1; i <= N; ++i)
        cin >> a[i];

    for(i = 1 ; i <= M; ++i)
        cin >> b[i];

    for(i = 1; i <= N; ++i)
        for(j = 1; j <= M; ++j){
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                ut[i][j] = (dp[i][j - 1] > dp[i - 1][j] ? 1 : 2);
            }
        }

    cout << dp[N][M] << '\n';
    i = N, j = M;
    int k = 1;

    while(i * j != 0){
        if(a[i] == b[j]){
            ans[k] = a[i];
            ++k; --i; --j;
        }
        else{
            if(ut[i][j] == 1) --j;
            else --i;
        }
    }

    for(i = k - 1; i >= 1; --i)
        cout << ans[i] << ' ';
    return 0;
}