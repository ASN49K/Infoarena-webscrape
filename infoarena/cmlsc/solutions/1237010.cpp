#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define LIM 1030

int n, m, A[LIM], B[LIM], dp[LIM][LIM];

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out","w", stdout);


    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // dp[i][k] = lungimea celui mai lung subsir comun pana la [i][k]
    for(int i = 0; i <= m; i++) {
        for(int k = 0; k <= n; k++) {
            if(A[i] == B[k]) {
                if(i + 1 <= m && k + 1 <= n)
                    dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][k] + 1);
            }
            if(k + 1 <= n)
                dp[i][k + 1] = max(dp[i][k + 1], dp[i][k]);
            if(i + 1 <= m)
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
        }
    }

    cout << dp[m][n] << "\n";

    int posi = m, posk = n;
    vector<int> res;
    for(int i = posi, k = posk; i > 0 && k > 0;) {
        if(A[i - 1] == B[k - 1] && dp[i - 1][k - 1] + 1 == dp[i][k]) {
            res.push_back(A[i - 1]);
            i--;
            k--;
        } else if(dp[i][k - 1] == dp[i][k]) {
            k--;
        } else {
            i--;
        }
    }

    int sz = res.size();
    for(int i = sz - 1; i > 0; i--) {
        cout << res[i] << " ";
    }
    if(sz >= 1)
        cout << res[0] << "\n";

	return 0;
}
