//ALEXANDRU MICLEA

#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

//#include <iostream>
#include <fstream>
ifstream cin("cmlsc.in"); ofstream cout("cmlsc.out");

//VARIABLES

int n, m;
int v1[1030];
int v2[1030];
int dp[1030][1030];
int ans = 0;

//FUNCTIONS

void give_answer(int i, int j) {
	//cout << i << " " << j << '\n';
	if (j < 1 || i < 1) {
		return;
	}
	if (v1[i] == v2[j] && dp[i - 1][j - 1] == dp[i][j] - 1) {
		give_answer(i - 1, j - 1);
		cout << v1[i] << " ";
		return;
	}
	if (dp[i - 1][j] == dp[i][j]) {
		give_answer(i - 1, j);
		return;
	}
	else if (dp[i][j - 1] == dp[i][j]) {
		give_answer(i, j - 1);
		return;
	}
}

//MAIN
int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v1[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> v2[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v1[i] == v2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n][m] << '\n';
	give_answer(n, m);

	return 0;
}