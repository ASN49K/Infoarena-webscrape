//ssense
#include<bits/stdc++.h>
//#include "/Users/mihaiesanu/testlib.h"
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef unsigned long long ull;
typedef long long  ll;
using namespace std;
#define FOR(n) for(int i=0;i<n;i++)
#define vt vector
#define sz(a) (int)a.size()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define NMAX 100005
#define MXL 1000000000000000000
#define PI 3.14159265
#define pb push_back
#define pf push_front
#define sc second
#define endl '\n'
#define fr first
#define int ll
#define ld long double

vector<int> ans;

void lcsAlgo(string S1, string S2, int m, int n) {
    int LCS_table[m + 1][n + 1];
    LCS_table[0][0] = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                LCS_table[i][j] = 0;
            }
            else if(S1[i - 1] == S2[j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            }
            else
            {
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
        }
    }
    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';
    int i = m, j = n;
    int len = 0;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S2[j-1];
            i--;
            j--;
            index--;
            len++;
        }
        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i = 0; i < len; i++)
    {
        ans.pb(lcsAlgo[i]-'0');
    }
}

int32_t main(){
    startt
    //freopen("cmlsc.in","r",stdin);
    //freopen("cmlsc.out","w",stdout);
    int m;
    int n;
    cin >> n >> m;
    string S1;
    string S2;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        S1.pb('0'+x);
    }
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        S2.pb('0'+x);
    }
    lcsAlgo(S1, S2, n, m);
    cout << ans.size() << endl;
    for(auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

