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
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;

uchar v1[MAXN], v2[MAXN];
int len[MAXN][MAXN];

int max3(int a, int b, int c) {
	return std::max(a, std::max(b, c));
}

int main() {
	assert(freopen(InFile, "r", stdin));
	assert(freopen(OutFile, "w", stdout));
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &v1[i]);
	for (int j = 1; j <= M; j++)
		scanf("%d", &v2[j]);
	for (int i = 0; i <= N; i++)
		len[i][0] = 0;
	for (int i = 0; i <= M; i++)
		len[0][i] = 0;

	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= M; j++) {
		len[i][j] = max3(len[i - 1][j - 1], len[i][j - 1], len[i - 1][j]);
		if (v1[i] == v2[j] && len[i][j] == len[i - 1][j - 1])
			len[i][j]++;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			fprintf(stderr, "%d ", len[i][j]);
		fprintf(stderr, "\n");
	}
		

	int i = N , j = M;
	printf("%d\n", len[i][j]);
	std::stack<uchar> S;
	while (i > 0 && j > 0) {
		int previ, prevj;
		if (len[i][j - 1] > len[i - 1][j]) {
			previ = i;
			prevj = j - 1;
		}
		else {
			previ = i - 1;
			prevj = j;
		}
		if (len[previ][prevj] < len[i][j])
			S.push(v1[i]);
		i = previ;
		j = prevj;
		/*if (len[i - 1][j - 1] < len[i][j])
			S.push(v1[i]);
		i--;
		j--;*/
	}
	while (!S.empty()) {
		printf("%u ", S.top());
		S.pop();
	}
	return 0;
}