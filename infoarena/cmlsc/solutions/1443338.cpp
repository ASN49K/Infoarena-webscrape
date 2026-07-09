#include <cstdio>
#include <cassert>
#include <algorithm>
#include <stack>
#define _submit
#ifdef _submit
#define InFile "cmlsc.in"
#define OutFile "cmlsc.out"
#else
#define InFile "fis.in"
#define OutFile "fis.out"
#endif

#define MAXN 1030
typedef unsigned char uchar;

uchar v1[MAXN], v2[MAXN];
int len[MAXN][MAXN];
short newelem[MAXN][MAXN];

int main() {
	assert(freopen(InFile, "r", stdin));
	assert(freopen(OutFile, "w", stdout));
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++)
		newelem[i][j] = -1;
	for (int i = 0; i < N; i++)
		scanf("%u", &v1[i]);
	for (int j = 0; j < M; j++)
		scanf("%u", &v2[j]);

	for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++) {
		if (i == 0 && j == 0)
			len[i][j] = 0;
		else if (i == 0)
			len[i][j] = len[i][j - 1];
		else if (j == 0)
			len[i][j] = len[i - 1][j];
		else
			len[i][j] = std::max(len[i - 1][j], len[i][j - 1]);
		if (v1[i] == v2[j]) {
			len[i][j]++;
			newelem[i][j] = short(v1[i]);
		}
	}

	int c1 = N - 1, c2 = M - 1;
	printf("%d\n", len[c1][c2]);
	std::stack<short> S;
	while (c1 >= 0 && c2 >= 0) {
		if (newelem[c1][c2] != -1)
			S.push(newelem[c1][c2]);
		if (c1 == 0)
			c2--;
		else if (c2 == 0)
			c1--;
		else if (len[c1 - 1][c2] > len[c1][c2-1])
			c1--;
		else
			c2--;
	}
	while (!S.empty()) {
		printf("%u ", S.top());
		S.pop();
	}
	return 0;
}