// infoarenaDFSnonRec.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <fstream>
#include <stack>
#include <assert.h>

#define MaxN 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M;
int s1[MaxN], s2[MaxN];
int best[MaxN][MaxN];
stack<int> result;

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	fin >> N >> M;
	for (int i = 1; i <= N; ++i)
		fin >> s1[i];
	for (int i = 1; i <= M; ++i)
		fin >> s2[i];

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (s1[i] == s2[j]) {
				best[i][j] = 1 + best[i - 1][j - 1];
			}
			else {
				best[i][j] = max(best[i - 1][j], best[i][j - 1]);
			}
		}
	}

	int i = N, j = M;
	while (i > 0 && j > 0) {
		if (s1[i] == s2[j]) {
			result.push(s1[i]);
			--i, --j;
		}
		else {
			if (best[i - 1][j] < best[i][j - 1]) {
				--j;
			}
			else {
				--i;
			}
		}
	}

	fout << best[N][M] << '\n';
	while (!result.empty()) {
		fout << result.top() << ' ';
		result.pop();
	}

	return 0;
}

