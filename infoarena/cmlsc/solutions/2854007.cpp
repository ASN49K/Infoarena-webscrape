#include <fstream>
#include <vector>

struct dpelem {
	int val;
	int ant1, ant2;
};

int vec1[1030], vec2[1030];

dpelem dp[1030][1030];

int main() {
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");
	int nrn1, nrn2;
	dpelem now;
	std::vector	<int> ans;
	fin >> nrn1 >> nrn2;
	for (int index = 1; index <= nrn1; index++) {
		fin >> vec1[index];
	}
	for (int index = 1; index <= nrn2; index++) {
		fin >> vec2[index];
	}
	for (int index = 1; index <= nrn1; index++) {
		for (int index2 = 1; index2 <= nrn2; index2++) {
			if (dp[index - 1][index2].val < dp[index][index2 - 1].val) {
				dp[index][index2] = dp[index][index2 - 1];
			}
			else {
				dp[index][index2] = dp[index - 1][index2];
			}
			if (vec1[index] == vec2[index2] && dp[index][index2].val <= dp[index - 1][index2 - 1].val) {
				dp[index][index2] = { dp[index - 1][index2 - 1].val + 1, index, index2 };
			}
		}
	}
	now = dp[nrn1][nrn2];
	while (now.ant1 != 0 && now.ant2 != 0) {
		ans.push_back(vec1[now.ant1]);
		now.ant1--;
		now.ant2--;
		now = dp[now.ant1][now.ant2];
	}
	fout << ans.size() << '\n';
	while (!ans.empty()) {
		fout << ans.back() << ' ';
		ans.pop_back();
	}
}