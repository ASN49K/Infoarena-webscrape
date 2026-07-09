#include <bits/stdc++.h>
using namespace std;
const int nmx = 1025;
/// lungimea celui mai lung subsir comun care se termina in poz i a sirului a si poz j a sirului b
int dp[nmx][nmx];
array<int,2> t[nmx][nmx];
int a[nmx], b[nmx];
#if 1
#define cin fin
#define cout fout
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#endif // 1
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int j=1;j<=m;j++)
        cin >> b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                t[i][j] = {i-1,j-1};
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                t[i][j] = {i-1,j};
            }
            else {
                dp[i][j] = dp[i][j-1];
                t[i][j] = {i,j-1};
            }
        }
    int mx = 0;
    array<int,2> mxi;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mx<dp[i][j]){
                mx = dp[i][j];
                mxi = {i,j};
            }
    array<int,2> it;
    cout << mx << "\n";
    it = mxi;
    vector<int> v;
    while(it[0] && it[1] ){
        if(a[it[0]] == b[it[1]])
            v.push_back(a[it[0]]);
        it = t[it[0]][it[1]];
    }
    reverse(v.begin(),v.end());
    for(int el : v)
        cout << el << " ";
}
