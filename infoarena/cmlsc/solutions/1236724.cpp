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
    for(int i = 1; i <= m; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    for(int i = 1; i <= m; i++) {
        for(int k = 1; k <= n; k++) {
            if(A[i] == B[k])
                dp[i][k] = max(dp[i][k], dp[i - 1][k - 1] + 1);
            else
                dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
        }
    }

    int mx = -1;
    for(int i = 1; i <= m; i++) {
        for(int k = 1; k <= n; k++) {
            mx = max(mx, dp[i][k]);
        }
    }
    cout << mx << "\n";

	return 0;
}
