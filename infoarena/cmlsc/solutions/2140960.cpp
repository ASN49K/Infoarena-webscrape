# include <stdio.h>
# include <algorithm>

# define MAX_N	1024

int N, M;
FILE *fin, *fout;
int w[MAX_N], m[MAX_N];

int common[MAX_N + 1][MAX_N + 1];
int maxLength, cMaxLength;
int solution[MAX_N];

int cmlscLength() {

	/* common[0][] = 0 | common[][0] = 0 */

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (w[i - 1] == m[j - 1])
				common[i][j] = common[i - 1][j - 1] + 1;
			else
				common[i][j] = std::max(common[i][j - 1], common[i - 1][j]);
		}
	}

	return common[N][M];
}

void printCmlscOneSolution() {
	for (int i = 0; i < maxLength; i++) {
		fprintf(fout, "%d ", solution[i]);
	}
}

void cmlscOneSolution(int i, int j) {

	if (i == 0 || j == 0 || cMaxLength < 0) {
		printCmlscOneSolution();
		return;
	}

	if (w[i - 1] == m[j - 1]) {
		solution[cMaxLength] = w[i - 1];
		cMaxLength--;
		cmlscOneSolution(i - 1, j - 1);
		return;
	}

	if (common[i][j - 1] > common[i - 1][j]) {
		cmlscOneSolution(i, j - 1);
	}
	else {
		cmlscOneSolution(i - 1, j);
	}

	return;
}

int main(void) {
	fin = fopen("cmlsc.in", "r");
	fout = fopen("cmlsc.out", "w");

	fscanf(fin, "%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		fscanf(fin, "%d", &w[i]);
	}

	for (int i = 0; i < M; i++) {
		fscanf(fin, "%d", &m[i]);
	}
	fclose(fin);

	maxLength = cmlscLength();

	fprintf(fout, "%d\n", maxLength);

	cMaxLength = maxLength - 1;
	cmlscOneSolution(N, M);

	fclose(fout);
	return 0;
}
