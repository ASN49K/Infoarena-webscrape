#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("cmlsc.in");
	ofstream fout("cmlsc.out");

	uint16_t dp[1030][1030], a[1030], b[1030];
	size_t n, m;

	fin >> m >> n;
	for(size_t i = 0; i < m; fin >> a[i++]);
	for(size_t i = 0; i < n; fin >> b[i++]);

	fill(&dp[0][0], &dp[0][0] + 1030*1030, static_cast<uint16_t>(0));

	for (size_t r = 1; r <= n; ++r)
		for (size_t c = 1; c <= m; ++c) {
			dp[r][c] = max<uint16_t>(dp[r-1][c], dp[r][c-1]);
			if (a[c-1] == b[r-1])
				dp[r][c] = max<uint16_t>(dp[r-1][c-1]+1, dp[r][c]);
		}
	
    uint16_t sol[1030], l = dp[n][m];

    size_t r(n), c(m);
    while ((r || c) && l) {
    	if (b[r-1] == a[c-1])
    		sol[--l] = a[--c], --r;
		else if (dp[r-1][c] == dp[r][c])
			--r;
		else
			--c;
	}

	fout << dp[n][m] << '\n';
	for (size_t i = 0; i < dp[n][m]; fout << sol[i++] << ' ');
	fout << endl;

	return 0;
}
