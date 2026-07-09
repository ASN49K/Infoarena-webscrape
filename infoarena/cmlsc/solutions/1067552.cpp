#include <fstream>
#include <vector>

using namespace std;

vector<int> lcs(const vector<int> &a,const vector<int> &b) {
    vector< vector<int> > dp(a.size() + 1,vector<int>(b.size(),0)); 
    for (int i = 1;i <= (int) a.size();i++) {
        for (int j = 1;j <= (int) b.size();j++) {
            dp[i][j] = (a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j],dp[i][j - 1])); 
        }
    }

    vector<int> ret(dp[a.size()][b.size()]);
    for (int i = (int)a.size(), j = (int)b.size(), k = dp[a.size()][b.size()];i > 0 && j > 0;) {
        if (a[i - 1] == b[j - 1]) {
            ret[--k] = a[i - 1];
            i--;
            j--;
        } else
        if (dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }

    return ret;
}


int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for (int i = 0;i < m;i++) {
        cin >> b[i];
    }

    vector<int> ans = lcs(a,b);
    cout << ans.size() << "\n";
    for (const int &x : ans) {
        cout << x << " ";
    }

    return 0;
}
