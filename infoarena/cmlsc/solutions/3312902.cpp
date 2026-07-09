#include <iostream>
#include <fstream>
#include <stdint.h>

const int32_t MAX_LEN = 1024;

int32_t vec1[MAX_LEN + 1], vec2[MAX_LEN + 1];
int32_t dp[MAX_LEN + 1][MAX_LEN + 1];
int32_t res[MAX_LEN + 1];

int main() {
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");

	int32_t m, n;
	fin >> m >> n;
	for(int32_t i = 1; i <= m; ++i)
		fin >> vec1[i];
	for(int32_t i = 1; i <= n; ++i)
		fin >> vec2[i];
	
	for(int32_t i = 1; i <= m; ++i) {
		for(int32_t j = 1; j <= n; ++j) {
			if(vec1[i] == vec2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				if(dp[i][j - 1] > dp[i - 1][j]) {
					dp[i][j] = dp[i][j - 1];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	int32_t len = dp[m][n];
	fout << len << '\n';

	int32_t ind = len, row = m, col = n;
	while(ind) {
		if(vec1[row] == vec2[col]) {
			res[ind--] = vec1[row];
			--row;
			--col;
		} else if(dp[row][col] == dp[row][col - 1]) {
			--col;
		} else {
			--row;
		}
	}

	for(int32_t i = 1; i <= len; ++i)
		fout << res[i] << ' ';

	fin.close();
	fout.close();

	return 0;
}