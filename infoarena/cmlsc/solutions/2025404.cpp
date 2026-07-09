#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector < vector <int> > vector2d;

vector <int> getGreatestCommonSubs(vector <int> a, vector <int> b){
    vector2d dp(a.size() + 1, vector <int>(b.size() + 1, 0));
    int n = a.size(), m = b.size();

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i-1][j-1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    vector <int> gcs;
    int ri = n, ci = m;
    while(ri > 0 && ci > 0){
        if (a[ri - 1] == b[ci - 1]){
            gcs.push_back(a[ri  - 1]);
            --ri;
            --ci;
        } else {
            if (dp[ri - 1][ci] > dp[ri][ci - 1]){
                --ri;
            } else {
                --ci;
            }
        }
    }
    reverse(gcs.begin(), gcs.end());
    return gcs;
}

int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m;
    cin >> n >> m;
    vector <int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j){
        cin >> b[j];
    }
    vector <int> gcs = getGreatestCommonSubs(a, b);
    cout << gcs.size() << "\n";
    for (auto& item : gcs){
        cout << item << " ";
    }
    return 0;
}
