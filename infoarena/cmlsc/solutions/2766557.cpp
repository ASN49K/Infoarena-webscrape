#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int nmax = 1e3 + 24;

int n, m, a[nmax + 1], b[nmax + 1];
int dp[nmax + 1][nmax + 1], l1, l2;
vector <int> ans;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    int i = n, j = m;
    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1]){
            j--;
        }
        else{
            i--;
        }
    }
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i] << " ";
    }
    return 0;
}
