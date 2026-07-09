#include <stdio.h>

#define MAX 1025
#define INPUT "lcs.in"
#define OUTPUT "lcs.out"
#define SUCCESS 0

int size = 0;
int s[MAX];
void findLCS(int a[], int n, int b[], int m) {
	int lcs[MAX][MAX]; // assume init with 0
	int i, j;

	for (i = 0; i <= n; i++) {
		lcs[i][0] = 0;
	}
	for (i = 0; i <= m; i++) {
		lcs[0][i] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				lcs[i + 1][j + 1] = 1 + lcs[i ][j];
			} else {
				if (lcs[i][j + 1] > lcs[i + 1][j]) {
					lcs[i + 1][j + 1] = lcs[i][j + 1];
				} else {
					lcs[i + 1][j + 1] = lcs[i + 1][j];
				}
			}
		}
	}

	size = lcs[n][m];
	i = n, j = m;
	int k = lcs[n][m] - 1;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			s[k--] = a[i - 1];	
			i--;
		} else {
			if (lcs[i - 1][j] > lcs[i][j - 1]) {
				i--;
			} else {
				j--;
			}
		}
	}
}

int main()
{
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int n, m, i;
	int a[MAX], b[MAX];

	scanf("%d %d\n", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	findLCS(a, n, b, m);
	printf("%d\n", size);
	for (i = 0; i < size; i++) {
		printf("%d ", s[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return SUCCESS;
}
