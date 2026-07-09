#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, a[1025], b[1025], dp[1025][1025];
vector <int> vec;

int main(){
    in>>n>>m;
    for(int i = 1; i <= n; ++i) in>>a[i];
    for(int i = 1; i <= m; ++i) in>>b[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    out<<dp[n][m]<<"\n";
    int i = n, j = m;
    while(i >= 1 && j >= 1)
        if(a[i] == b[j]) vec.push_back(a[i]), --i, --j;
        else{
            if(dp[i-1][j]>dp[i][j-1]) --i;
            else                      --j;
        }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); ++i) out<<vec[i]<<" ";
    return 0;
}
