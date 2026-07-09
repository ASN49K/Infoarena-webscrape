#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fi("cmlsc.in");
    ofstream fo("cmlsc.out");
    int n, m;
    fi>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)
        fi>>a[i];
    for(int i=1;i<=m;i++)
        fi>>b[i];

    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i=n, j=m;
    vector<int> res;
    while(i) {
        if(a[i] == b[j]) {
            res.push_back(a[i]);
            i--, j--;
        }
        else if(dp[i-1][j] < dp[i][j-1]) {
            j--;
        }
        else {
            i--;
        }
    }
    fo<<res.size()<<"\n";
    reverse(res.begin(), res.end());
    for(auto it:res) {
        fo<< it<<" ";
    }
    fi.close();
    fo.close();
    return 0;
}
