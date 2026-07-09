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
    for(int i = 0; i < m; i++) {
        for(int k = 0; k < n; k++) {
            if(A[i] == B[k])
                dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][k] + 1);
            else {
                dp[i][k + 1] = max(dp[i][k + 1], dp[i][k]);
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
            }
        }
    }

    cout << dp[m][n] << "\n";

    vector<int> res;
    for(int i = m, k = n; i >= 0;) {
        if(i - 1 >= 0 && k - 1 >= 0 && A[i - 1] == B[k - 1]) {
            res.push_back(A[i - 1]);
            i--;
            k--;
        } else if(k - 1 >= 0 && i - 1 >= 0 && dp[i][k - 1] > dp[i - 1][k]) {
            k--;
        } else {
            i--;
        }
    }

    for(int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << "\n";
	return 0;
}
