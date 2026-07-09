#include <fstream>
#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cstring>
#include <climits>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
//#define int long long
//#define int short
#define pb push_back
#define f first
#define s second
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int nmax = (1 << 10);

int n, m, a[nmax + 5], b[nmax + 5];
int dp[nmax + 5][nmax + 5];

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void handleinput(){
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for (int i = 1; i <= m; i++){
        cin>>b[i];
    }
}

void builddp(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

string getsol(){
    int i = n, j = m;
    string rez;
    while (i && j){
        if (a[i] == b[j]){
            rez += to_string(a[i]);
            i--;
            j--;
        }
        else{
            if (dp[i][j] == dp[i - 1][j]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(rez.begin(), rez.end());
    return rez;
}

void handleoutput(){
    cout<<dp[n][m]<<"\n";
    for (char& c : getsol()){
        cout<<c<<" ";
    }
}

signed main(){
    fastio();
    handleinput();
    builddp();
    handleoutput();
}
